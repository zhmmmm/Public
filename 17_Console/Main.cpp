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
		std::cout << "�ź��������ǣ�"<<age<<"�꣡" << std::endl;
	}
};

int main()
{
	Student *Obj;
	Obj = new Student();
	Obj->Print();
	Obj->Print();

	system("pause");
	delete Obj;
	Obj = NULL;
	return 0;
}