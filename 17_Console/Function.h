#pragma once
#include <list>
//������
//struct Bullet
//{
//	int X;
//	int Y;
//};
////�����͵��ӵ�
//std::list<Bullet> mBullet;
//if (true)//ĳ������
//{
//	Bullet Temp;//�½�һ���ӵ�
//	Temp.X = 0;//�ӵ��ĵ�ǰλ��
//	Temp.Y = 0;
//	mBullet.push_back(Temp);//���½��õ��ӵ���������
//}
////�߼�����
//for (std::list<Bullet>::iterator i = mBullet.begin(); i != mBullet.end(); i++)//���������е����е��ӵ�
//{
//	if (true)
//	{
//		i = mBullet.erase(i);//Խ����ӵ��ͷ�
//	}
//	else//δԽ����ӵ������ƶ�
//	{
//		i->Y++;
//	}
//}
////����
//for (std::list<Bullet>::iterator i = mBullet.begin(); i != mBullet.end(); i++)//���������е����е��ӵ�
//{
//	//ͨ��i->Y,i->X ��Ϊ���������
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