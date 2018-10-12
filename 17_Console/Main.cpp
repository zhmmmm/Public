#include <iostream>
#include <vector>
#include <list>
#include "Hash.h"

using namespace std;

int YesReturnValueFunctionCall()
{
	return 1;

	//int num = 10;
	//__asm
	//{
	//	call F;
	//	push eax;
	//	mov num, eax;
	//	pop eax;
	//}
	//std::cout << num << std::endl;

	//int num = 0;
	//__asm
	//{
	//	xor eax, eax;
	//	call YesReturnValueFunctionCall;
	//	push eax;
	//	mov num, eax;
	//	pop eax;
	//}
	//std::cout << num << std::endl;
}

void ParameterFunction(const char *num)
{
	printf(num);
	//const char num[] = "123\n";
	//__asm
	//{
	//	mov eax, offset num;
	//	push eax;
	//	call ParameterFunction;
	//	pop ebx;
	//}

}

void ordinaryAdd()
{
	//int num = 1;
	//int num2 = 234;
	//__asm
	//{
	//	push eax;
	//	push ebx;
	//	mov eax, num;
	//	mov ebx, num2;
	//	add eax, ebx;
	//	mov num, eax;
	//	mov num2, ebx;
	//	pop eax;
	//	pop ebx;
	//}
	//std::cout << num << std::endl;
}
//=============================================
int find_half(int* p, int len, int data)
{
	int Temp = 0;
	int e = len - 1;
	while (Temp <= e)
	{
		int TempLen = (Temp + e) / 2;
		if (data < p[TempLen])
		{
			e = TempLen - 1;
		}
		else if (p[TempLen] < data)
		{
			Temp = TempLen + 1;
		}
		else
		{
			return TempLen;
		}
	}
	return -1;
}

bool operator < (const std::string& s1, const std::string& s2)
{
	if (strcmp(s1.c_str(), s2.c_str()) < 0)
	{
		return true;
	}
	return false;
}

int hashfunc(const std::string& key)
{
	return (key[0] + key[key.length() - 1]);
	//hash函数的原则：
	//1、尽量简单
	//2、结果尽量离散
	//3、冲突尽量少
	/*
		Hash<std::string, int> aaa(256, hashfunc);
	aaa.Insert("123", 123);
	aaa.Insert("456", 456);
	aaa.Insert("abc", 789);
	aaa.Insert("def", 101112);
	aaa.Insert("bbb", 131415);
	aaa.Insert("xyz", 161718);
	aaa.Insert("qwe", 192021);
	aaa.Insert("ijk", 222324);
	aaa["666"] = 999;


	Hash<std::string, int>::LPAIR it = aaa.Find("123");
	cout << "(" << it->Key.c_str() << "," << it->Data << ")" << endl;
	cout << aaa["666"] << endl;
	cout << aaa["bbb"] << endl;
	*/
}
//==============================================
//数结构
typedef struct TreeNode
{
	char data;
	std::vector<TreeNode> child;
}TREENODE, *LPTREENODE;
//先根遍历
void RootFirst(TREENODE& t)
{
	cout << t.data << " ";
	for (unsigned int i = 0; i < t.child.size(); i++)
	{
		RootFirst(t.child[i]);
	}
}
//后根遍历
void RootAfter(TREENODE& t)
{
	for (unsigned int i = 0; i < t.child.size(); i++)
	{
		RootAfter(t.child[i]);
	}
	cout << t.data << " ";
}
//层序遍历
void LayerView(TREENODE& t)
{
	std::list<TREENODE> helplist;
	//先将根节点压入队列
	helplist.push_back(t);
	//循环判断队列是否为空
	while (!helplist.empty())
	{
		//取出队列第一个元素
		TREENODE temp = helplist.front();
		cout << temp.data << " ";
		//将该元素的所有子节点依次加入到队列的尾部
		for (unsigned int i = 0; i < temp.child.size(); i++)
		{
			helplist.push_back(temp.child[i]);
		}
		helplist.pop_front();
	}
}
//求树的大小
int SizeOfTree(TREENODE& t, int& num)
{
	num++;
	for (unsigned int i = 0; i < t.child.size(); i++)
	{
		SizeOfTree(t.child[i], num);
	}
	return num;
}
//求树的高度
int HeightOfTree(TREENODE& t, int deep = 0)
{
	int n = deep + 1;
	int m = -1;
	for (unsigned int i = 0; i < t.child.size(); i++)
	{
		m = HeightOfTree(t.child[i], deep + 1);
		if (m > n)
		{
			n = m;
		}
	}
	return n;
}
/*
	//TREENODE A;
	//A.data = 'A';
	//TREENODE temp;
	//A.child.push_back(temp);
	//A.child.push_back(temp);
	//A.child.push_back(temp);
	//A.child.push_back(temp);
	//A.child[0].data = 'B';
	//A.child[1].data = 'C';
	//A.child[2].data = 'D';
	//A.child[3].data = 'E';

	//TREENODE& C = A.child[1];
	//C.child.push_back(temp);
	//C.child[0].data = 'F';

	//TREENODE& F = C.child[0];
	//F.child.push_back(temp);
	//F.child.push_back(temp);
	//F.child[0].data = 'J';
	//F.child[1].data = 'K';

	//TREENODE& D = A.child[2];
	//D.child.push_back(temp);
	//D.child[0].data = 'G';

	//TREENODE& E = A.child[3];
	//E.child.push_back(temp);
	//E.child.push_back(temp);
	//E.child[0].data = 'H';
	//E.child[1].data = 'I';

	//TREENODE& I = E.child[1];
	//I.child.push_back(temp);
	//I.child.push_back(temp);
	//I.child.push_back(temp);
	//I.child[0].data = 'L';
	//I.child[1].data = 'M';
	//I.child[2].data = 'N';


	//cout << "先根遍历树A结果：" << endl;
	//RootFirst(A);
	//cout << endl << "后根遍历树A结果：" << endl;
	//RootAfter(A);
	//cout << endl;

	//cout << "层序遍历树A结果：" << endl;
	//LayerView(A);
	//cout << endl;

	//int num = 0;
	//cout << "求树A的大小结果：" << SizeOfTree(A, num) << endl;


	//cout << HeightOfTree(A) << endl;
	//cout << HeightOfTree(A.child[0]) << endl;
	//cout << HeightOfTree(C) << endl;
*/
//===============================
#define DATA_INT int
typedef struct _node
{
	int           data; //数据
	_node   *Next; //下一个
}NODE, *LPNODE;
class myclass
{
private:
	int num;
	LPNODE head;
public:
	myclass()//构造
	{
		head = NULL;
		num = 0;
	}
	void copyfunction(const myclass &data) //拷贝函数
	{
		LPNODE datahead = data.head;
		LPNODE temp = head;
		while (datahead)
		{
			LPNODE tempnode = new NODE;
			tempnode->data = datahead->data;
			tempnode->Next = NULL;
			if (temp == NULL)
			{
				temp = head = tempnode;
			}
			else
			{
				datahead = datahead->Next;
				temp = temp->Next;
			}
			temp->Next = tempnode;
		}
		num = data.num;
	}
	myclass(const myclass &data) //拷贝构造
	{
		copyfunction(data);
	}
	myclass &operator = (const myclass &data) //同类赋值
	{
		if (&data != this)
		{
			clearfunction();
			copyfunction(data);
		}
		return *this;
	}

	void pushHead(const DATA_INT &data) //添加在头部
	{
		LPNODE tempnode = new NODE; //新的节点
		tempnode->data = data;
		tempnode->Next = head;
		head = tempnode;
		num++;
	}
	void pushend(const DATA_INT &data) //添加在尾部
	{
		LPNODE temp = head;
		LPNODE tempnode = new NODE; //新的节点
		tempnode->data = data;
		tempnode->Next = NULL;

		if (temp = NULL)
		{
			tempnode->Next = head;
			head = tempnode;
		}
		else
		{
			while (temp->Next)
			{
				temp = temp->Next;
			}
			temp->Next = tempnode;
		}
		num++;
	}
	void insert(int pos, const DATA_INT &data)
	{
		if (pos >= num) { pushend(data); return; }
		LPNODE tempnode = NULL; //当前的前一个节点
		LPNODE temp2node = head; //要插入位置的节点

		LPNODE newnode = new NODE; //新的要插入的节点
		newnode->data = data;
		newnode->Next = NULL;
		for (int i = 0; i < pos; ++i)
		{
			if (tempnode == NULL)
			{
				tempnode = head;
			}
			else
			{
				tempnode = tempnode->Next;
			}
			temp2node = tempnode->Next;
		}
		newnode->Next = temp2node;
		if (tempnode == NULL)
		{
			head = newnode;
		}
		else
		{
			tempnode->Next = newnode;
		}
	}
	void function(const myclass &data)
	{
		std::cout << data.num << std::endl;
		std::cout << data.head->data << std::endl;
	}

	void clearfunction()//释放函数
	{
		if (head)
		{
			LPNODE temp = head;
			while (head)//当前有值
			{
				head = head->Next;//下一个的整个
				delete temp; //删除head
				temp = head;//下一个的整个
			}
		}
		num = 0;
	}
	~myclass()//析构
	{
		clearfunction();
	}
};

//二叉树节点结构体
typedef struct stBinaryTreeNode
{
	char data;
	stBinaryTreeNode* father;
	stBinaryTreeNode* left;
	stBinaryTreeNode* right;
}BINTREENODE, *LPBINTREENODE;

template<typename DATA> class BinaryTree
{
public:
	LPBINTREENODE createTreeNode(char data)
	{
		LPBINTREENODE node = new BINTREENODE;
		node->data = data;
		node->father = node->left = node->right = NULL;
		return node;
	}
	LPBINTREENODE cutTree(LPBINTREENODE node)
	{
		//做安全的判断
		if (node == NULL)
		{
			return NULL;
		}
		if (node->father != NULL)
		{
			//如果是左孩子
			if (node->father->left == node)
			{
				node->father->left = NULL;
			}
			else
			{
				node->father->right = NULL;
			}
			node->father = NULL;
		}
		return node;
	}
	LPBINTREENODE insertTree(LPBINTREENODE root, LPBINTREENODE node, bool insertleft = true)
	{
		if (root == NULL || node == NULL)
			return NULL;

		//将要插入的位置砍树操作

		LPBINTREENODE beCutTreeNode = NULL;
		if (insertleft)
		{
			beCutTreeNode = cutTree(root->left);
			root->left = node;
		}
		else
		{
			beCutTreeNode = cutTree(root->right);
			root->right = node;
		}
		node->father = root;
		return beCutTreeNode;
	}
	void rootFirstPrint(LPBINTREENODE node)
	{
		if (node == NULL)
			return;
		cout << node->data << " ";
		rootFirstPrint(node->left);
		rootFirstPrint(node->right);
	}
	void rootAfterPrint(LPBINTREENODE node)
	{
		if (node == NULL)
			return;
		rootAfterPrint(node->left);
		rootAfterPrint(node->right);
		cout << node->data << " ";
	}
	void rootMiddlePrint(LPBINTREENODE node)
	{
		if (node == NULL)
			return;
		rootMiddlePrint(node->left);
		cout << node->data << " ";
		rootMiddlePrint(node->right);
	}
	void layerViewPrint(LPBINTREENODE node)
	{
		if (node == NULL)
			return;

		list<LPBINTREENODE> NodeDeque;
		NodeDeque.push_back(node);

		while (!NodeDeque.empty())
		{
			LPBINTREENODE tempNode = NodeDeque.front();
			cout << tempNode->data << " ";
			if (tempNode->left)
			{
				NodeDeque.push_back(tempNode->left);
			}
			if (tempNode->right)
			{
				NodeDeque.push_back(tempNode->right);
			}
			NodeDeque.pop_front();
		}
	}
	void DeleteTree(LPBINTREENODE& root)
	{
		if (root == NULL)
			return;

		root = cutTree(root);

		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
		root = NULL;
	}
	LPBINTREENODE CopyTree(LPBINTREENODE root)
	{
		if (root == NULL)
			return NULL;

		LPBINTREENODE node = createTreeNode(root->data);

		node->left = CopyTree(root->left);
		if (node->left)
		{
			node->left->father = node;
		}
		node->right = CopyTree(root->right);
		if (node->right)
		{
			node->right->father = node;
		}
		return node;
	}
};
template<typename Data> class MaxHeap_Int
{
public:
	//构造(这里写的是将数组的数据在构造的时候就加入到堆中)
	MaxHeap_Int(int len, int* Data)
	{
		mCapaCity = len + 1;
		mData = new int[mCapaCity];
		mSize = 0;
		for (int i = 0; i < len; i++)
		{
			_PushData(Data[i]);
		}
	}
	~MaxHeap_Int()
	{
		delete[] mData;
		mData = NULL;
		mSize = mCapaCity = 0;
	}
	//获取已经排好序的数据到数组
	void GetSortData(int* Data)
	{
		int maxsize = mSize;
		for (int i = 0; i < maxsize; i++)
		{
			Data[i] = _PopData();
		}
	}
	void PrintHeapData()
	{
		if (mData)
		{
			for (int i = 0; i < mSize; i++)
			{
				cout << mData[i + 1] << " ";
			}
			cout << endl;
		}
	}
protected:
	//往堆中插入数据
	void _PushData(int data)
	{
		//表示当前插入的数据是根节点
		mData[mSize + 1] = data;
		mSize++;
		int curindex = mSize;
		int fatherindex = curindex / 2;

		while (fatherindex > 0 && mData[fatherindex] < mData[curindex])
		{
			int temp = mData[fatherindex];
			mData[fatherindex] = mData[curindex];
			mData[curindex] = temp;
			curindex = fatherindex;
			fatherindex = curindex / 2;
		}
	}
	//从堆中弹出数据
	int _PopData()
	{
		int podeddata = mData[1];

		int nullindex = 1;//空出来的位置
		int nextindex = nullindex * 2 + 1;//假设要交换的是右边的节点

		while (nextindex <= mSize)
		{
			//如果左节点比有节点大
			if (mData[nextindex - 1] > mData[nextindex])
			{
				nextindex--;//实际上要交换的位置应该是左节点
			}

			//交换节点的数据
			int temp = mData[nullindex];
			mData[nullindex] = mData[nextindex];
			//重新计算空节点和下一个要交换的节点
			nullindex = nextindex;
			nextindex = nullindex * 2 + 1;
		}

		//拿最后一个节点的数据进行补位
		mData[nullindex] = mData[mSize];


		//调整补位以后的数据的优先级
		while (nullindex > 1)
		{
			if (mData[nullindex / 2] < mData[nullindex])
			{
				int temp = mData[nullindex / 2];
				mData[nullindex / 2] = mData[nullindex];
				mData[nullindex] = temp;
				nullindex /= 2;
			}
			else {
				break;
			}
		}

		mSize--;
		return podeddata;
	}
private:
	int mCapaCity;
	int mSize;
	int* mData;
};
int main()
{
	//BinaryTree<char> Obj;
	//LPBINTREENODE A = Obj.createTreeNode('A');
	//LPBINTREENODE B = Obj.createTreeNode('B');
	//LPBINTREENODE C = Obj.createTreeNode('C');
	//LPBINTREENODE D = Obj.createTreeNode('D');
	//LPBINTREENODE E = Obj.createTreeNode('E');
	//LPBINTREENODE F = Obj.createTreeNode('F');
	//LPBINTREENODE G = Obj.createTreeNode('G');
	//LPBINTREENODE H = Obj.createTreeNode('H');
	//LPBINTREENODE I = Obj.createTreeNode('I');
	//LPBINTREENODE J = Obj.createTreeNode('J');
	//Obj.insertTree(A, B);
	//Obj.insertTree(A, C, false);
	//Obj.insertTree(B, D);
	//Obj.insertTree(B, E, false);
	//Obj.insertTree(E, G);
	//Obj.insertTree(C, F);
	//Obj.insertTree(F, H, false);
	//Obj.insertTree(H, I);
	//Obj.insertTree(H, J, false);
	//cout << "先根遍历打印：" << endl;
	//Obj.rootFirstPrint(A);
	//cout << endl << "后根遍历打印：" << endl;
	//Obj.rootAfterPrint(A);
	//cout << endl << "中序遍历打印：" << endl;
	//Obj.rootMiddlePrint(A);
	//cout << endl << "层序遍历打印：" << endl;
	//Obj.layerViewPrint(A);
	//cout << endl;
	//Obj.DeleteTree(B);
	//cout << endl << "层序遍历打印：" << endl;
	//Obj.layerViewPrint(A);
	//cout << endl;
	//cout << B << endl;
	//LPBINTREENODE K = Obj.CopyTree(F);
	//cout << endl << "层序遍历打印：" << endl;
	//Obj.layerViewPrint(K);
	//cout << endl;
	//cout << K->father << endl;
	////释放
	//Obj.DeleteTree(A);
	//Obj.DeleteTree(K);

	//int arr[16] = { 4,7,9,0,8,6,12,34,21,3,5,17,18,10,4,2 };
	//MaxHeap_Int<int> Obj(16,arr);
	//Obj.PrintHeapData();
	//int narr[16] = { 0 };
	//Obj.GetSortData(narr);
	//for (int i = 0; i < 16; i++)
	//{
	//	cout << narr[i] << " ";
	//}
	//cout << endl;



	system("pause");
	return 0;
}
