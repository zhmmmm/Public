#pragma once
template<typename KEY, typename DATA>
class Hash
{
public:
	typedef struct pair//键值对结构体 
	{
		KEY Key;//键
		DATA Data;//值
	}PAIR, *LPAIR;
private:
	//顺序表结构体
	typedef struct Node
	{
		int _Capacity;//容量
		int _Size;//大小
		LPAIR _Data;//数据指针
	}NODE, *LPNODE;

	int m_Capacity;//哈希表的容量
	int m_Size;//hash表的长度（键值对个数）
	LPNODE m_Hash;//哈希表的顺序表数组

	int(*m_pHashFunc)(const KEY& key);//哈希函数指针成员变量
public:
	//构造
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

	//拷贝构造
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
				//得到容量
				m_Hash[i]._Capacity = that.m_Hash[i]._Capacity;

				//得到长度
				m_Hash[i]._Size = that.m_Hash[i]._Size;

				//得到数据
				m_Hash[i]._Data = new PAIR[m_Hash[i]._Capacity];
				for (int j = 0; j < m_Hash[i]._Size; ++j)
				{
					m_Hash[i]._Data[j] = that.m_Hash[i]._Data[j];
				}
			}
		}
	}
	//同类赋值？
	Hash& operator = (const Hash& that)
	{
		if (this != &that)
		{
			//释放所有堆内存
			for (int i = 0; i < m_Capacity; ++i)
			{
				if (m_Hash[i]._Capacity != 0)
					delete[] m_Hash[i]._Data;
			}
			delete[] m_Hash;

			//拷贝that中所有数据
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
					//得到容量
					m_Hash[i]._Capacity = that.m_Hash[i]._Capacity;

					//得到长度
					m_Hash[i]._Size = that.m_Hash[i]._Size;

					//得到数据
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
	//析构
	~Hash()
	{
		for (int i = 0; i < m_Capacity; ++i)
		{
			if (m_Hash[i]._Capacity != 0)
				delete[] m_Hash[i]._Data;
		}
		delete[] m_Hash;
	}

	//插入
	bool Insert(const KEY& key, const DATA& data)
	{
		//根据键和哈希函数得到下标
		//int index = m_pHashFunc(key) % m_Capacity;
		int Index = (*m_pHashFunc)(key) % m_Capacity;

		//当前下标上的顺序表已经创建
		if (m_Hash[Index]._Capacity > 0)
		{
			//折半插入
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
					//不能放入相同的KEY
					return false;
				}
			}

			//扩容
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

			//将新的键值对放入begin位置
			//m表示的是将要后移的数据的个数
			//为了给我们要插入的数据挪位置
			int m = m_Hash[Index]._Size - begin;
			for (int i = 0; i < m; ++i)
			{
				m_Hash[Index]._Data[m_Hash[Index]._Size - i] = m_Hash[Index]._Data[m_Hash[Index]._Size - 1 - i];
			}
			m_Hash[Index]._Data[begin].Key = key;
			m_Hash[Index]._Data[begin].Data = data;
			m_Hash[Index]._Size += 1;
		}
		//当前下标上的顺序表还未创建
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

	//重载下标运算符
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
	//查找
	PAIR* Find(const KEY& key)
	{
		//根据键和哈希函数得到下标
		int Index = (*m_pHashFunc)(key) % m_Capacity;

		//如果该下标上的顺序表为空则不存在该键值对
		if (m_Hash[Index]._Capacity == 0)
		{
			return 0;
		}

		//存在顺序表然后进行折半查找
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
	//删除？
	bool Erase(const KEY& key)
	{
		//根据键和哈希函数得到下标
		int Index = (*m_pHashFunc)(key) % m_Capacity;

		//如果该下标上的顺序表为空则不存在该键值对
		if (m_Hash[Index]._Capacity == 0)
		{
			return false;
		}

		//存在顺序表然后进行折半查找
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
				//从顺序表中删除键值对
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

	//长度
	int Size()
	{
		return m_Size;
	}

	//清空
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

