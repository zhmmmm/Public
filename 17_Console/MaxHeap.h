#pragma once
#include <iostream>
using namespace std;

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