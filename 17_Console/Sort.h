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
	//ð������
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
	//��������
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
	//��������
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
	//�۰�����
	void BinSort(DATA Arr, LEN Len) //��int������д�С���������   
	{
		for (int i = 1; i < Len; i++) //��ʼ ��a[0]��Ϊ�������У���a[1]��ʼ�ҵ���ǰԪ��a[i]Ӧ�÷��õ�λ��   
		{
			int low = 0, high = i - 1, mid;//ÿ��Ѱ��a[i]��λ�ã���Ҫ������Щ����   
			while (low <= high) //����˼��ѭ��Ѱ��a[i]��λ��   
			{
				mid = (low + high) / 2;
				if (Arr[i] <= Arr[mid])
					high = mid - 1;  //highָ���С   
				else
					low = mid + 1;   //lowָ������   
			}  //ѭ��������low����a[i]Ӧ�÷��õ�λ��   

			int temp = Arr[i];
			for (int j = i; j > low; j--)  //��Ԫ�����ƽ��  
				Arr[j] = Arr[j - 1];
			Arr[low] = temp;   //��Ԫ��temp = a[i] ���õ�lowλ��   
		}
	}
	//ѡ������
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