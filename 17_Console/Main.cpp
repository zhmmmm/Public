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
	//hash������ԭ��
	//1��������
	//2�����������ɢ
	//3����ͻ������
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
//���ṹ
typedef struct TreeNode
{
	char data;
	std::vector<TreeNode> child;
}TREENODE, *LPTREENODE;
//�ȸ�����
void RootFirst(TREENODE& t)
{
	cout << t.data << " ";
	for (unsigned int i = 0; i < t.child.size(); i++)
	{
		RootFirst(t.child[i]);
	}
}
//�������
void RootAfter(TREENODE& t)
{
	for (unsigned int i = 0; i < t.child.size(); i++)
	{
		RootAfter(t.child[i]);
	}
	cout << t.data << " ";
}
//�������
void LayerView(TREENODE& t)
{
	std::list<TREENODE> helplist;
	//�Ƚ����ڵ�ѹ�����
	helplist.push_back(t);
	//ѭ���ж϶����Ƿ�Ϊ��
	while (!helplist.empty())
	{
		//ȡ�����е�һ��Ԫ��
		TREENODE temp = helplist.front();
		cout << temp.data << " ";
		//����Ԫ�ص������ӽڵ����μ��뵽���е�β��
		for (unsigned int i = 0; i < temp.child.size(); i++)
		{
			helplist.push_back(temp.child[i]);
		}
		helplist.pop_front();
	}
}
//�����Ĵ�С
int SizeOfTree(TREENODE& t, int& num)
{
	num++;
	for (unsigned int i = 0; i < t.child.size(); i++)
	{
		SizeOfTree(t.child[i], num);
	}
	return num;
}
//�����ĸ߶�
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


	//cout << "�ȸ�������A�����" << endl;
	//RootFirst(A);
	//cout << endl << "���������A�����" << endl;
	//RootAfter(A);
	//cout << endl;

	//cout << "���������A�����" << endl;
	//LayerView(A);
	//cout << endl;

	//int num = 0;
	//cout << "����A�Ĵ�С�����" << SizeOfTree(A, num) << endl;


	//cout << HeightOfTree(A) << endl;
	//cout << HeightOfTree(A.child[0]) << endl;
	//cout << HeightOfTree(C) << endl;
*/
//===============================
#define DATA_INT int
typedef struct _node
{
	int           data; //����
	_node   *Next; //��һ��
}NODE, *LPNODE;
class myclass
{
private:
	int num;
	LPNODE head;
public:
	myclass()//����
	{
		head = NULL;
		num = 0;
	}
	void copyfunction(const myclass &data) //��������
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
	myclass(const myclass &data) //��������
	{
		copyfunction(data);
	}
	myclass &operator = (const myclass &data) //ͬ�ำֵ
	{
		if (&data != this)
		{
			clearfunction();
			copyfunction(data);
		}
		return *this;
	}

	void pushHead(const DATA_INT &data) //�����ͷ��
	{
		LPNODE tempnode = new NODE; //�µĽڵ�
		tempnode->data = data;
		tempnode->Next = head;
		head = tempnode;
		num++;
	}
	void pushend(const DATA_INT &data) //�����β��
	{
		LPNODE temp = head;
		LPNODE tempnode = new NODE; //�µĽڵ�
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
		LPNODE tempnode = NULL; //��ǰ��ǰһ���ڵ�
		LPNODE temp2node = head; //Ҫ����λ�õĽڵ�

		LPNODE newnode = new NODE; //�µ�Ҫ����Ľڵ�
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

	void clearfunction()//�ͷź���
	{
		if (head)
		{
			LPNODE temp = head;
			while (head)//��ǰ��ֵ
			{
				head = head->Next;//��һ��������
				delete temp; //ɾ��head
				temp = head;//��һ��������
			}
		}
		num = 0;
	}
	~myclass()//����
	{
		clearfunction();
	}
};

struct coor
{
	int x;
	int y;
};

class str
{

public:
	static coor Coor;
	str()
	{

	}
	~str()
	{

	}
};

coor str::Coor = { 100,100};

int main()
{
	std::cout << str::Coor.x << " " << str::Coor.y << std::endl;



	system("pause");
	return 0;
}
