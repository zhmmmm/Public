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


int main()
{

	TREENODE A;
	A.data = 'A';
	TREENODE temp;
	A.child.push_back(temp);
	A.child.push_back(temp);
	A.child.push_back(temp);
	A.child.push_back(temp);
	A.child[0].data = 'B';
	A.child[1].data = 'C';
	A.child[2].data = 'D';
	A.child[3].data = 'E';

	TREENODE& C = A.child[1];
	C.child.push_back(temp);
	C.child[0].data = 'F';

	TREENODE& F = C.child[0];
	F.child.push_back(temp);
	F.child.push_back(temp);
	F.child[0].data = 'J';
	F.child[1].data = 'K';

	TREENODE& D = A.child[2];
	D.child.push_back(temp);
	D.child[0].data = 'G';

	TREENODE& E = A.child[3];
	E.child.push_back(temp);
	E.child.push_back(temp);
	E.child[0].data = 'H';
	E.child[1].data = 'I';

	TREENODE& I = E.child[1];
	I.child.push_back(temp);
	I.child.push_back(temp);
	I.child.push_back(temp);
	I.child[0].data = 'L';
	I.child[1].data = 'M';
	I.child[2].data = 'N';


	cout << "先根遍历树A结果：" << endl;
	RootFirst(A);
	cout << endl << "后根遍历树A结果：" << endl;
	RootAfter(A);
	cout << endl;

	cout << "层序遍历树A结果：" << endl;
	LayerView(A);
	cout << endl;

	int num = 0;
	cout << "求树A的大小结果：" << SizeOfTree(A, num) << endl;


	cout << HeightOfTree(A) << endl;
	cout << HeightOfTree(A.child[0]) << endl;
	cout << HeightOfTree(C) << endl;


	system("pause");
	return 0;
}
