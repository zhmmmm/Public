#include <iostream>
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include <map>
#include <vector>
#include <list>
#include "Hash.h"
#include "BinaryTree.h"
#include "MaxHeap.h"
#include "BinarySearchTree.h"
#include "Sort.h"



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
//===============================��������
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
//======ģ����
class MyClass
{
	int num;
public:
	MyClass()
	{
		num = 100;
	}
	template<typename Type>
	void Prit(Type num)
	{
		std::cout << "��ģ����� " << this->num + num << std::endl;
	}
	//MyClass Obj;
	//Obj.Prit<float>(100.123);
	//MyClass Obj;
	//Obj.Prit(100);
};
//��ģ��
template<typename T> class Class
{
	int num;
public:
	Class()
	{
		num = 1000;
	}
	void Print(T num)
	{
		std::cout << "��ģ����� " << this->num + num << std::endl;
	}
	//Class<int> Obj;
	//Obj.Print(123);
};




int main()
{
	int Arr[10] = {9,1,2,8,3,10,5,6,7,4};
	int TempArr[10] = { 0 };
	Sort<int*, int> SortObj;
	SortObj.ChoiceSort(Arr, 10);
	SortObj.Print(Arr,10);


	std::cout << std::endl;
	system("pause");
	return 0;
}
