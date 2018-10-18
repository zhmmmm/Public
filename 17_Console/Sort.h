#pragma once
#include <iostream>

template<typename DATA,typename LEN>
class Sort
{

public:
	//√∞≈›≈≈–Ú
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
	void PrintBubbleSort(DATA Arr, LEN Len)
	{
		std::cout << "√∞≈›Ω·π˚Œ™£∫";
		for (int i = 0; i < Len; i++)
		{
			std::cout<< Arr[i] << " ";
		}
	}
	//øÏÀŸ≈≈–Ú
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
	void PrintFastSort(DATA Arr, LEN Len)
	{
		for (int i = 0; i < Len; i++)
		{
			std::cout << Arr[i] << " ";
		}
	}
	//≤Â»Î≈≈–Ú
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
	void PrintInsertSort(DATA Arr, LEN Len)
	{
		for (int i = 0; i < Len; i++)
		{
			std::cout << Arr[i] << " ";
		}
	}
};