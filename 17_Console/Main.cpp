#include <iostream>
#include <tinyxml.h>

/*
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include <map>
#include <vector>
#include <list>
*/
#define __START__  {
#define __END__       }

# if 0 int YesReturnValueFunctionCall()
{
	return 1;

	//int num = 10;
	//__asm
	//{
	//	call F;
	//	push eax;
	//	mov num, eax;
	//	pop eax;
	//}
	//std::cout << num << std::endl;

	//int num = 0;
	//__asm
	//{
	//	xor eax, eax;
	//	call YesReturnValueFunctionCall;
	//	push eax;
	//	mov num, eax;
	//	pop eax;
	//}
	//std::cout << num << std::endl;
}
void ParameterFunction(const char *num)
{
	printf(num);
	//const char num[] = "123\n";
	//__asm
	//{
	//	mov eax, offset num;
	//	push eax;
	//	call ParameterFunction;
	//	pop ebx;
	//}

}
void ordinaryAdd()
{
	//int num = 1;
	//int num2 = 234;
	//__asm
	//{
	//	push eax;
	//	push ebx;
	//	mov eax, num;
	//	mov ebx, num2;
	//	add eax, ebx;
	//	mov num, eax;
	//	mov num2, ebx;
	//	pop eax;
	//	pop ebx;
	//}
	//std::cout << num << std::endl;
}
#endif


int main()
{
	TiXmlDocument Doc;
	TiXmlElement *Root = new TiXmlElement("Root");
	TiXmlElement *Ele = new TiXmlElement("ELEMENTS");
	TiXmlElement *Ele_0 = new TiXmlElement("Test");

	Ele_0->SetAttribute("Name", "ÎÒ");
	Ele->SetAttribute("Name", "ÕÅºÆÂü");
	Ele->SetAttribute("Age", "20");


	Root->LinkEndChild(Ele);
	Root->LinkEndChild(Ele_0);
	Doc.LinkEndChild(Root);
	Doc.SaveFile("MyTest.txt");

	//TiXmlDocument Doc("MyTest.txt");
	//if (Doc.LoadFile())
	//{
	//	TiXmlElement *Root = Doc.FirstChildElement("Root");
	//	for (TiXmlElement *Ele = Root->FirstChildElement("ELEMENTS"); Ele != NULL; Ele = Ele->NextSiblingElement())
	//	{
	//		std::cout << Ele->Attribute("Name")<<std::endl;
	//		std::cout << Ele->GetText() << std::endl;
	//	}
	//}

	system("pause");
	return 0;
}
