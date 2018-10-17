#pragma once
template<typename TK, typename TD>
class BinarySearchTree
{
public:
	struct BSTNode
	{
		TK key;//���������жϱȽϴ�С�����ݣ������ظ��ģ�
		TD data;
		BSTNode* left;
		BSTNode* right;
		BSTNode* parent;
	};
private:
	BSTNode* m_Root;//���ڵ�
	int m_Size;//�ж��ٸ��ڵ㣬������¼�����ٱ�����ʱ��
public:
	//���캯��
	BinarySearchTree()
		:m_Root(NULL),
		m_Size(0) {}
	//��������
	~BinarySearchTree()
	{
		clear();
	}
	//��������
	BinarySearchTree(const BinarySearchTree& that)
	{
		if (this != &that)
		{
			m_Root = _CopyBinaryTree(that.m_Root);
			m_Size = that.m_Size;
		}
	}
	//ͬ�ำֵ
	BinarySearchTree& operator = (const BinarySearchTree& that)
	{
		if (this != &that)
		{
			clear();
			m_Root = _CopyBinaryTree(that.m_Root);
			m_Size = that.m_Size;
		}
	}
	//ȡ�ڵ�����
	int Size()
	{
		return m_Size;//ֱ�ӷ��ز��ñ���
	}
	//�������Ƿ�Ϊ��
	bool Empty()
	{
		if (NULL == m_Root)
			return true;
		return false;
	}
	void print()
	{
		_PrintTree(m_Root);
	}
	//����
	BSTNode* Insert(TK key, TD data)
	{
		if (m_Size == 0)//��û�нڵ��ʱ�򣬲���ľ��Ǹ��ڵ�
		{
			m_Root = new BSTNode;
			m_Root->key = key;
			m_Root->data = data;
			m_Root->left = m_Root->right = m_Root->parent = NULL;
			m_Size++;
			return m_Root;
		}

		BSTNode* p = m_Root;//�Ӹ���ʼ�Ƚ�
		BSTNode* per = m_Root;
		bool isleft = false;


		while (p)//�ҵ�Ҫ����Ľڵ�ĸ��ڵ�
		{
			per = p;
			if (key < p->key)
			{
				p = p->left;
				isleft = true;
			}
			else if (p->key < key)
			{
				p = p->right;
				isleft = false;
			}
			else//���ܳ���key��ȵ��������֤KeyΨһ��
			{
				//����ȵ������ֱ�ӷ���
				return NULL;
			}
		}

		if (isleft)
		{
			per->left = new BSTNode;
			per->left->parent = per;
			per->left->left = per->left->right = NULL;
			per->left->key = key;
			per->left->data = data;
			m_Size++;
			return per->left;
		}
		else
		{
			per->right = new BSTNode;
			per->right->parent = per;
			per->right->left = per->right->right = NULL;
			per->right->key = key;
			per->right->data = data;
			m_Size++;
			return per->right;
		}
		return NULL;
	}
	//����key��ȡ����
	bool Find(TK key, const TD& data)
	{
		if (m_Size == 0)
		{
			return false;
		}
		BSTNode* p = m_Root;//�Ӹ���ʼ�Ƚ�
		while (p)//�ҵ�Ҫ����Ľڵ�ĸ��ڵ�
		{
			if (key < p->key)
			{
				p = p->left;
			}
			else if (p->key < key)
			{
				p = p->right;
			}
			else
			{
				data = p->data;
				return true;
			}
		}
		return false;
	}
	//����key��ȡ�������ڽڵ�
	BSTNode* Find(TK key)
	{
		if (m_Size == 0)
		{
			return NULL;
		}
		BSTNode* p = m_Root;//�Ӹ���ʼ�Ƚ�
		while (p)//�ҵ�Ҫ����Ľڵ�ĸ��ڵ�
		{
			if (key < p->key)
			{
				p = p->left;
			}
			else if (p->key < key)
			{
				p = p->right;
			}
			else//��ʱkey���
			{
				return p;
			}
		}
		//����ѭ����ʾû�в��ҵ����ݽڵ�
		return NULL;
	}
	//�����±�����
	TD& operator[](const TK& key)
	{
		BSTNode* p = Find(key);
		if (p)
		{
			return p->data;
		}
		TD temp;
		return Insert(key, temp);
	}

	//ɾ���ڵ�
	void erase(TK key)
	{
		//�����ҵ�Ҫɾ���Ľڵ�
		BSTNode* p = Find(key);
		if (!p) { return; }//û���ҵ�Ҫɾ���Ľڵ�ֱ�ӷ���

		//����ҵ���Ҫɾ���Ľڵ㣬�����¼����������
		//1�����Ҷ��ޣ�ֱ��ɾ��
		//2���������ҡ�ֱ��ɾ���ڵ㣬������ڵ����֮
		//3����������ֱ��ɾ���ڵ㣬�����ҽڵ����֮
		//4�����Ҷ��е�������豻ɾ�ڵ�ΪP�����������֮���
		//���q����P���ȹ�����һֱ����ֱ����ڵ�Ϊ�յ�ʱ�򣩣�
		//������ת��Ϊɾ��q��Ҳ����ת��Ϊ����1,3

		if (p->left == NULL && p->right == NULL)//���Ҷ���
		{
			if (p == m_Root)
			{
				m_Root = NULL;
			}
			else
			{
				//�����Ҫɾ���Ľڵ��Ǹ��ڵ����߻����ұ�
				if (p->parent->left == p)
				{
					p->parent->left = NULL;
				}
				else
				{
					p->parent->right = NULL;
				}
			}
			delete p;//���ɾ��p�ڵ�
		}
		else if (p->right != NULL && p->left == NULL)//��������
		{
			if (p == m_Root)
			{
				m_Root = p->right;
				m_Root->parent = NULL;
			}
			else
			{
				//�ж�Ҫɾ���Ľڵ��Ǹ��ڵ����߻����ұ�
				if (p->parent->left == p)
				{
					p->parent->left = p->right;
				}
				else
				{
					p->parent->right = p->right;
				}
				//�������ô���ڵ�ĸ��ڵ�
				p->right->parent = p->parent;
			}
			delete p;//ɾ��Ҫɾ���Ľڵ�
		}
		else if (p->left != NULL && p->right == NULL)//��������
		{
			if (p == m_Root)
			{
				m_Root = p->left;
				m_Root->parent = NULL;
			}
			else
			{
				if (p->parent->left == p)
				{
					p->parent->left = p->left;
				}
				else
				{
					p->parent->right = p->left;
				}
				p->left->parent = p->parent;
			}
			delete p;
		}
		else//���Ҷ���
		{
			BSTNode* q = _FindLeft(p->right);//�ҵ���������ĺ�̽ڵ�

			//�������ڵ��key��data��ֵ��ԭҪɾ���Ľڵ�
			p->key = q->key;
			p->data = q->data;

			//��ʱ����ת��Ϊɾ��q�ڵ�

			if (q->left == NULL && q->right == NULL)//���Ҷ���
			{
				if (q->parent->left == q)
				{
					q->parent->left = NULL;
				}
				else
				{
					q->parent->right = NULL;
				}
				delete q;
			}
			else if (q->right != NULL && q->left == NULL)//��������
			{
				if (q->parent->left == q)
				{
					q->parent->left = q->right;
				}
				else
				{
					q->parent->right = q->right;
				}
				q->right->parent = q->parent;
				delete q;
			}
		}
		m_Size--;
	}
	//�����
	void clear()
	{
		_deleteTree(m_Root);
		m_Size = 0;
	}
protected:
	BSTNode* _FindLeft(BSTNode* p)
	{
		if (!p)
		{
			return NULL;
		}

		while (p->left)
		{
			p = p->left;
		}
		/*if (p->left)
		{
			_FindLeft(p->left);
		}*/
		return p;
	}

	BSTNode* _cutBTN(BSTNode* b)
	{
		if (!b || !b->parent) { return b; }

		if (b->parent->left == b)
		{
			b->parent->left = NULL;
		}
		else if (b->parent->right == b)
		{
			b->parent->right = NULL;
		}
		b->parent = NULL;
		return b;
	}
	void _deleteTree(BSTNode*& b)//
	{
		if (!b)
		{
			return;
		}
		_deleteTree(b->left);
		_deleteTree(b->right);
		_cutBTN(b);
		delete b;
		b = NULL;
	}
	BSTNode* _CopyBinaryTree(BSTNode* p)
	{
		if (p == 0) { return 0; }
		BSTNode* q = new BSTNode;//new��һ���µĽڵ����
		q->parent = 0;
		q->data = p->data;
		q->left = _CopyBinaryTree(p->left);//�ݹ鸴��������
		if (q->left)
		{
			q->left->parent = q;
		}
		q->right = _CopyBinaryTree(p->right);//�ݹ鸴��������
		if (q->right)
		{
			q->right->parent = q;
		}
		return q;
	}
	void _PrintTree(BSTNode* t)
	{
		if (NULL == t)
		{
			return;
		}
		cout << t->key << " ";
		_PrintTree(t->left);
		_PrintTree(t->right);
	}
	/*
		BinarySearchTree<int, int> bst;
	bst.Insert(4, 0);
	bst.Insert(7, 0);
	bst.Insert(9, 0);
	bst.Insert(0, 0);
	bst.Insert(8, 0);
	bst.Insert(6, 0);
	bst.Insert(12, 0);
	bst.Insert(34, 0);
	bst.Insert(21, 0);
	bst.Insert(3, 0);
	bst.Insert(5, 0);
	bst.print();
	bst.erase(7);
	cout << endl;
	bst.print();
	*/
};