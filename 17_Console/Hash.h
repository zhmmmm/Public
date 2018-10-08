#pragma once
template<typename KEY, typename DATA>
class Hash
{
public:
	typedef struct pair//��ֵ�Խṹ�� 
	{
		KEY Key;//��
		DATA Data;//ֵ
	}PAIR, *LPAIR;
private:
	//˳���ṹ��
	typedef struct Node
	{
		int _Capacity;//����
		int _Size;//��С
		LPAIR _Data;//����ָ��
	}NODE, *LPNODE;

	int m_Capacity;//��ϣ�������
	int m_Size;//hash��ĳ��ȣ���ֵ�Ը�����
	LPNODE m_Hash;//��ϣ���˳�������

	int(*m_pHashFunc)(const KEY& key);//��ϣ����ָ���Ա����
public:
	//����
	Hash(int Capacity, int(*HashFunc)(const KEY& key))
		:m_Capacity(Capacity),
		m_Size(0),
		m_Hash(new NODE[m_Capacity]),
		m_pHashFunc(HashFunc)
	{
		for (int i = 0; i < m_Capacity; ++i)
		{
			m_Hash[i]._Capacity = 0;
			m_Hash[i]._Size = 0;
			m_Hash[i]._Data = NULL;
		}
	}

	//��������
	Hash(const Hash& that)
		:m_Capacity(that.m_Capacity),
		m_Size(that.m_Size),
		m_Hash(new NODE[m_Capacity]),
		m_pHashFunc(that.m_pHashFunc)
	{
		for (int i = 0; i < m_Capacity; ++i)
		{
			if (that.m_Hash[i]._Capacity == 0)
			{
				m_Hash[i]._Capacity = 0;
				m_Hash[i]._Size = 0;
				m_Hash[i]._Data = NULL;
			}
			else
			{
				//�õ�����
				m_Hash[i]._Capacity = that.m_Hash[i]._Capacity;

				//�õ�����
				m_Hash[i]._Size = that.m_Hash[i]._Size;

				//�õ�����
				m_Hash[i]._Data = new PAIR[m_Hash[i]._Capacity];
				for (int j = 0; j < m_Hash[i]._Size; ++j)
				{
					m_Hash[i]._Data[j] = that.m_Hash[i]._Data[j];
				}
			}
		}
	}
	//ͬ�ำֵ��
	Hash& operator = (const Hash& that)
	{
		if (this != &that)
		{
			//�ͷ����ж��ڴ�
			for (int i = 0; i < m_Capacity; ++i)
			{
				if (m_Hash[i]._Capacity != 0)
					delete[] m_Hash[i]._Data;
			}
			delete[] m_Hash;

			//����that����������
			m_Capacity = that.m_Capacity;
			m_Size = that.m_Size;
			m_Hash = new NODE[m_Capacity];
			m_pHashFunc = that.m_pHashFunc;
			for (int i = 0; i < m_Capacity; ++i)
			{
				if (that.m_Hash[i]._Capacity == 0)
				{
					m_Hash[i]._Capacity = 0;
				}
				else
				{
					//�õ�����
					m_Hash[i]._Capacity = that.m_Hash[i]._Capacity;

					//�õ�����
					m_Hash[i]._Size = that.m_Hash[i]._Size;

					//�õ�����
					m_Hash[i]._Data = new PAIR[m_Hash[i]._Capacity];
					for (int j = 0; j < m_Hash[i]._Size; ++j)
					{
						m_Hash[i]._Data[j] = that.m_Hash[i]._Data[j];
					}
				}
			}
		}

		return *this;
	}
	//����
	~Hash()
	{
		for (int i = 0; i < m_Capacity; ++i)
		{
			if (m_Hash[i]._Capacity != 0)
				delete[] m_Hash[i]._Data;
		}
		delete[] m_Hash;
	}

	//����
	bool Insert(const KEY& key, const DATA& data)
	{
		//���ݼ��͹�ϣ�����õ��±�
		//int index = m_pHashFunc(key) % m_Capacity;
		int Index = (*m_pHashFunc)(key) % m_Capacity;

		//��ǰ�±��ϵ�˳����Ѿ�����
		if (m_Hash[Index]._Capacity > 0)
		{
			//�۰����
			int begin = 0, end = m_Hash[Index]._Size - 1;
			while (begin <= end)
			{
				int half = (begin + end) / 2;
				if (key < m_Hash[Index]._Data[half].Key)
				{
					end = half - 1;
				}
				else if (m_Hash[Index]._Data[half].Key < key)
				{
					begin = half + 1;
				}
				else
				{
					//���ܷ�����ͬ��KEY
					return false;
				}
			}

			//����
			if (m_Hash[Index]._Size == m_Hash[Index]._Capacity)
			{
				m_Hash[Index]._Capacity *= 2;
				PAIR* p = new PAIR[m_Hash[Index]._Capacity];
				for (int i = 0; i < m_Hash[Index]._Size; ++i)
				{
					p[i] = m_Hash[Index]._Data[i];
				}
				delete[] m_Hash[Index]._Data;
				m_Hash[Index]._Data = p;
			}

			//���µļ�ֵ�Է���beginλ��
			//m��ʾ���ǽ�Ҫ���Ƶ����ݵĸ���
			//Ϊ�˸�����Ҫ���������Ųλ��
			int m = m_Hash[Index]._Size - begin;
			for (int i = 0; i < m; ++i)
			{
				m_Hash[Index]._Data[m_Hash[Index]._Size - i] = m_Hash[Index]._Data[m_Hash[Index]._Size - 1 - i];
			}
			m_Hash[Index]._Data[begin].Key = key;
			m_Hash[Index]._Data[begin].Data = data;
			m_Hash[Index]._Size += 1;
		}
		//��ǰ�±��ϵ�˳���δ����
		else
		{
			m_Hash[Index]._Capacity = 4;
			m_Hash[Index]._Size = 1;
			m_Hash[Index]._Data = new PAIR[m_Hash[Index]._Capacity];
			m_Hash[Index]._Data[0].Key = key;
			m_Hash[Index]._Data[0].Data = data;
		}

		m_Size += 1;

		return true;
	}

	//�����±������
	DATA& operator [](const KEY& key)
	{
		LPAIR p = this->Find(key);
		if (p == NULL)
		{
			DATA a;
			this->Insert(key, a);
			p = this->Find(key);
		}
		return p->Data;
	}
	//����
	PAIR* Find(const KEY& key)
	{
		//���ݼ��͹�ϣ�����õ��±�
		int Index = (*m_pHashFunc)(key) % m_Capacity;

		//������±��ϵ�˳���Ϊ���򲻴��ڸü�ֵ��
		if (m_Hash[Index]._Capacity == 0)
		{
			return 0;
		}

		//����˳���Ȼ������۰����
		int begin = 0, end = m_Hash[Index]._Size - 1;
		while (begin <= end)
		{
			int half = (begin + end) / 2;
			if (key < m_Hash[Index]._Data[half].Key)
			{
				end = half - 1;
			}
			else if (m_Hash[Index]._Data[half].Key < key)
			{
				begin = half + 1;
			}
			else
			{
				return &m_Hash[Index]._Data[half];
			}
		}
		return NULL;
	}
	//ɾ����
	bool Erase(const KEY& key)
	{
		//���ݼ��͹�ϣ�����õ��±�
		int Index = (*m_pHashFunc)(key) % m_Capacity;

		//������±��ϵ�˳���Ϊ���򲻴��ڸü�ֵ��
		if (m_Hash[Index]._Capacity == 0)
		{
			return false;
		}

		//����˳���Ȼ������۰����
		int begin = 0, end = m_Hash[Index]._Size - 1;
		while (begin <= end)
		{
			int half = (begin + end) / 2;
			if (key < m_Hash[Index]._Data[half].Key)
			{
				end = half - 1;
			}
			else if (m_Hash[Index]._Data[half].Key < key)
			{
				begin = half + 1;
			}
			else
			{
				//��˳�����ɾ����ֵ��
				int m = m_Hash[Index]._Size - half - 1;
				for (int i = 0; i < m; ++i)
				{
					m_Hash[Index]._Data[half + i] = m_Hash[Index]._Data[half + 1 + i];
				}
				m_Hash[Index]._Size -= 1;
				m_Size -= 1;

				return true;
			}
		}
		return false;
	}

	//����
	int Size()
	{
		return m_Size;
	}

	//���
	void Clear()
	{
		for (int i = 0; i < m_Capacity; ++i)
		{
			if (m_Hash[i]._Capacity > 0)
				m_Hash[i]._Size = 0;
		}
		m_Size = 0;
	}
};

