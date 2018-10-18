#pragma once
#include <iostream>

template<typename DATA,typename LEN>
class Sort
{

public:
	void Print(DATA Arr, LEN Len)
	{
		for (int i = 0; i < Len; i++)
		{
			std::cout << Arr[i] << " ";
		}
		std::cout << std::endl;
	}
	//冒泡排序
	void BubbleSort(DATA Arr, LEN Len)
	{
		for (int i = 0; i < Len; i++)
		{
			for (int j = i + 1; j < Len; j++)
			{
				if (Arr[i] > Arr[j])
				{
					int Temp = Arr[i];
					Arr[i] = Arr[j];
					Arr[j] = Temp;
				}
			}
		}
	}
	//快速排序
	void FastSort(DATA Arr, LEN StartIndex, LEN EndIndex)
	{
		int Key = Arr[StartIndex];
		int Left = StartIndex;
		int Right = EndIndex;
		if (Left >= Right) { return; }
		while (Left < Right)
		{
			while (Left < Right && Arr[Right] >= Key){Right--;}
			Arr[Left] = Arr[Right];
			while (Left < Right && Arr[Left] < Key){Left++;}
			Arr[Right] = Arr[Left];
		}
		Arr[Right] = Key;
		FastSort(Arr,StartIndex, Right - 1);
		FastSort(Arr,Right + 1, EndIndex);
	}
	//插入排序
	void InsertSort(DATA Arr, LEN Len)
	{
		int j = 0;
		int TempData = 0;
		for (int i = 0; i < Len; i++)
		{
			j = i;
			TempData = *(Arr + i);
			while (j > 0 && TempData < Arr[j - 1])
			{
				Arr[j] = Arr[j - 1];
				j--;
			}
			Arr[j] = TempData;
		}
	}
	//折半排序
	void BinSort(DATA Arr, LEN Len) //对int数组进行从小到大的排序   
	{
		for (int i = 1; i < Len; i++) //开始 以a[0]作为有序序列，从a[1]开始找到当前元素a[i]应该放置的位置   
		{
			int low = 0, high = i - 1, mid;//每次寻找a[i]的位置，都要更新这些数据   
			while (low <= high) //二分思想循环寻找a[i]的位置   
			{
				mid = (low + high) / 2;
				if (Arr[i] <= Arr[mid])
					high = mid - 1;  //high指针减小   
				else
					low = mid + 1;   //low指针增加   
			}  //循环结束，low就是a[i]应该放置的位置   

			int temp = Arr[i];
			for (int j = i; j > low; j--)  //将元素向后平移  
				Arr[j] = Arr[j - 1];
			Arr[low] = temp;   //将元素temp = a[i] 放置到low位置   
		}
	}
	//选择排序
	void ChoiceSort(DATA Arr, LEN Len)
	{
		for (int i = 0; i < Len; i++)
		{
			int K = i;
			for (int j = i + 1; j < Len; j++)
			{
				if (Arr[K] > Arr[j])
				{
					K = j;
				}
			}
			int Temp = Arr[i];
			Arr[i] = Arr[K];
			Arr[K] = Temp;
		}
	}
};