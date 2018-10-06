#include <iostream>



int **Return()
{
	int **m = new int*[10];
	for (int i = 0; i < 10; i++)
	{
		m[i] = new int[10];
	}
	return m;
}

int main()
{
	int **p = Return();
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			p[i][j] = j + 1;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << p[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int Map[10][10] = { 0 };
	std::cout << "ÄÚ´æ¿½±´Ö®ºó£¡" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Map[i][j] = p[i][j];
			std::cout << Map[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int temp = 0;
	delete[] p;
	p = NULL;
	system("pause");
	return 0;
}
