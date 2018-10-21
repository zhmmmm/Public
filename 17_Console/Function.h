#pragma once
#include <list>
//功能性
//struct Bullet
//{
//	int X;
//	int Y;
//};
////链表型的子弹
//std::list<Bullet> mBullet;
//if (true)//某键按下
//{
//	Bullet Temp;//新建一个子弹
//	Temp.X = 0;//子弹的当前位置
//	Temp.Y = 0;
//	mBullet.push_back(Temp);//把新建好的子弹存入链表
//}
////逻辑更新
//for (std::list<Bullet>::iterator i = mBullet.begin(); i != mBullet.end(); i++)//遍历链表中的所有的子弹
//{
//	if (true)
//	{
//		i = mBullet.erase(i);//越界的子弹释放
//	}
//	else//未越界的子弹继续移动
//	{
//		i->Y++;
//	}
//}
////绘制
//for (std::list<Bullet>::iterator i = mBullet.begin(); i != mBullet.end(); i++)//遍历链表中的所有的子弹
//{
//	//通过i->Y,i->X 作为左边来绘制
//}
void ___Number(int *Num,int *Number)
{
	int Add_10 = 10;
	int i = 0;
	int Arr[256] = { 0 };
	int Arr_10 = 1;
	while (true)
	{
		int Temp = (*Num) % Add_10;
		Arr[i] = Temp / Arr_10;
		(*Num) -= Temp;
		Add_10 *= 10;
		i++;
		if ((*Num) == 0) { break; }
		Arr_10 *= 10;
	}
	for (int j = 0; j < i; j++)
	{
		(*Number) += (Arr[j] * Arr_10);
		Arr_10 /= 10;
	}
}