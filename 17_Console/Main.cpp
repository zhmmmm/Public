#include <iostream>

class Student
{
	int age;
public:
	Student()
	{
		age = 18;
	}
	void Print()
	{
		std::cout << "ÕÅºÆÂüÄêÁäÊÇ£º"<<age<<"Ëê£¡" << std::endl;
	}
};

int main()
{
	Student *Obj;
	Obj = new Student();
	Obj->Print();

	system("pause");
	delete Obj;
	Obj = NULL;
	return 0;
}
