#pragma once
#include <iostream>
using namespace std;

template<typename Data> class MaxHeap_Int
{
public:
	//����(����д���ǽ�����������ڹ����ʱ��ͼ��뵽����)
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
	//��ȡ�Ѿ��ź�������ݵ�����
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
	//�����в�������
	void _PushData(int data)
	{
		//��ʾ��ǰ����������Ǹ��ڵ�
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
	//�Ӷ��е�������
	int _PopData()
	{
		int podeddata = mData[1];

		int nullindex = 1;//�ճ�����λ��
		int nextindex = nullindex * 2 + 1;//����Ҫ���������ұߵĽڵ�

		while (nextindex <= mSize)
		{
			//�����ڵ���нڵ��
			if (mData[nextindex - 1] > mData[nextindex])
			{
				nextindex--;//ʵ����Ҫ������λ��Ӧ������ڵ�
			}

			//�����ڵ������
			int temp = mData[nullindex];
			mData[nullindex] = mData[nextindex];
			//���¼���սڵ����һ��Ҫ�����Ľڵ�
			nullindex = nextindex;
			nextindex = nullindex * 2 + 1;
		}

		//�����һ���ڵ�����ݽ��в�λ
		mData[nullindex] = mData[mSize];


		//������λ�Ժ�����ݵ����ȼ�
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
//int arr[16] = { 4,7,9,0,8,6,12,34,21,3,5,17,18,10,4,2 };
//MaxHeap_Int<int*> a(16, arr);
//a.PrintHeapData();
//
//int narr[16];
//a.GetSortData(narr);
//for (int i = 0; i < 16; i++)
//{
//	cout << narr[i] << " ";
//}
//cout << endl;