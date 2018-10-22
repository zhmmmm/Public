#include <iostream>
#include <atlbase.h>
//#include <float.h>
//#include <winperf.h>
//#include <afxtempl.h>  
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
	//CString dwTotalPhys;
	//CString dwTotalVirtual;

	//   TODO:     Add   extra   initialization   here   
	MEMORYSTATUS   Mem;
	//   get   the   memory   status   
	GlobalMemoryStatus(&Mem);

	DWORD dwSize = (DWORD)Mem.dwTotalPhys / (1024 * 1024);
	DWORD dwVirtSize = (DWORD)Mem.dwTotalVirtual / (1024 * 1024);

	int Temp = 0;

	//dwTotalPhys.Format(_T("物理内存:%ld MB"), dwSize);
	//dwTotalVirtual.Format(_T("虚拟内存:%ld MB"), dwVirtSize);

	system("pause");
	return 0;
}
