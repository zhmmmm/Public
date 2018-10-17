#pragma once
template<typename TK, typename TD>
class BinarySearchTree
{
public:
	struct BSTNode
	{
		TK key;//用来搜索判断比较大小的依据（不能重复的）
		TD data;
		BSTNode* left;
		BSTNode* right;
		BSTNode* parent;
	};
private:
	BSTNode* m_Root;//根节点
	int m_Size;//有多少个节点，辅助记录，减少遍历的时间
public:
	//构造函数
	BinarySearchTree()
		:m_Root(NULL),
		m_Size(0) {}
	//析构函数
	~BinarySearchTree()
	{
		clear();
	}
	//拷贝构造
	BinarySearchTree(const BinarySearchTree& that)
	{
		if (this != &that)
		{
			m_Root = _CopyBinaryTree(that.m_Root);
			m_Size = that.m_Size;
		}
	}
	//同类赋值
	BinarySearchTree& operator = (const BinarySearchTree& that)
	{
		if (this != &that)
		{
			clear();
			m_Root = _CopyBinaryTree(that.m_Root);
			m_Size = that.m_Size;
		}
	}
	//取节点数量
	int Size()
	{
		return m_Size;//直接返回不用遍历
	}
	//搜索树是否为空
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
	//插入
	BSTNode* Insert(TK key, TD data)
	{
		if (m_Size == 0)//当没有节点的时候，插入的就是根节点
		{
			m_Root = new BSTNode;
			m_Root->key = key;
			m_Root->data = data;
			m_Root->left = m_Root->right = m_Root->parent = NULL;
			m_Size++;
			return m_Root;
		}

		BSTNode* p = m_Root;//从根开始比较
		BSTNode* per = m_Root;
		bool isleft = false;


		while (p)//找到要插入的节点的父节点
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
			else//不能出现key相等的情况，保证Key唯一性
			{
				//在相等的情况下直接返回
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
	//查找key获取数据
	bool Find(TK key, const TD& data)
	{
		if (m_Size == 0)
		{
			return false;
		}
		BSTNode* p = m_Root;//从根开始比较
		while (p)//找到要插入的节点的父节点
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
	//查找key获取数据所在节点
	BSTNode* Find(TK key)
	{
		if (m_Size == 0)
		{
			return NULL;
		}
		BSTNode* p = m_Root;//从根开始比较
		while (p)//找到要插入的节点的父节点
		{
			if (key < p->key)
			{
				p = p->left;
			}
			else if (p->key < key)
			{
				p = p->right;
			}
			else//此时key相等
			{
				return p;
			}
		}
		//跳出循环表示没有查找到数据节点
		return NULL;
	}
	//重载下标运算
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

	//删除节点
	void erase(TK key)
	{
		//首先找到要删除的节点
		BSTNode* p = Find(key);
		if (!p) { return; }//没有找到要删除的节点直接返回

		//如果找到了要删除的节点，分以下几种情况讨论
		//1、左右都无，直接删除
		//2、有左无右、直接删除节点，并用左节点代替之
		//3、有右无左、直接删除节点，并用右节点代替之
		//4、左右都有的情况，设被删节点为P，其中序遍历之后继
		//结点q代替P（先拐右再一直拐左，直到左节点为空的时候），
		//将问题转换为删除q，也就是转换为问题1,3

		if (p->left == NULL && p->right == NULL)//左右都无
		{
			if (p == m_Root)
			{
				m_Root = NULL;
			}
			else
			{
				//分清楚要删除的节点是父节点的左边还是右边
				if (p->parent->left == p)
				{
					p->parent->left = NULL;
				}
				else
				{
					p->parent->right = NULL;
				}
			}
			delete p;//最后删除p节点
		}
		else if (p->right != NULL && p->left == NULL)//有右无左
		{
			if (p == m_Root)
			{
				m_Root = p->right;
				m_Root->parent = NULL;
			}
			else
			{
				//判断要删除的节点是父节点的左边还是右边
				if (p->parent->left == p)
				{
					p->parent->left = p->right;
				}
				else
				{
					p->parent->right = p->right;
				}
				//从新设置代替节点的父节点
				p->right->parent = p->parent;
			}
			delete p;//删除要删除的节点
		}
		else if (p->left != NULL && p->right == NULL)//有左无右
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
		else//左右都有
		{
			BSTNode* q = _FindLeft(p->right);//找到中序遍历的后继节点

			//将后续节点的key和data赋值给原要删除的节点
			p->key = q->key;
			p->data = q->data;

			//此时问题转换为删除q节点

			if (q->left == NULL && q->right == NULL)//左右都无
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
			else if (q->right != NULL && q->left == NULL)//有右无左
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
	//清空树
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
		BSTNode* q = new BSTNode;//new了一个新的节点出来
		q->parent = 0;
		q->data = p->data;
		q->left = _CopyBinaryTree(p->left);//递归复制左子树
		if (q->left)
		{
			q->left->parent = q;
		}
		q->right = _CopyBinaryTree(p->right);//递归复制右子树
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