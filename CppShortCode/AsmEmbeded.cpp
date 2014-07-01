#include <iostream>
#include <stdio.h>
using namespace std;
int CheckMMX( )
{
	int isMMX=0;
	__asm
	{
		mov eax,1;
		cpuid;
		test edx,00800000h;
		jz  NotSupport;
		mov  isMMX,1;
		jmp over;
NotSupport:
		mov isMMX,0;
over:
	}
	return isMMX;
}
int CheckSSE()
{
	int isSSE = 0;
	_asm 
{
		mov eax, 1
		cpuid
		shr edx,0x1A
		jnc NotSupport
		mov isSSE, 1
NotSupport:
}
	return isSSE;
}
//
#define RDTSC _asm _emit 0x0f _asm _emit 0x31
#pragma warning (push)
#pragma warning (disable:4035)
inline unsigned __int64 timestamp()
{
	RDTSC
}
#pragma warning (pop)
//此程序也展示了内嵌汇编应如何使用C++中的指针
void main( )
{
	
	cout<<CheckMMX()<<CheckSSE()<<endl;
	unsigned int a,b;
	a=10;
	b=5;
	unsigned int *c = &a;
	__asm //下面是内嵌汇编...
	{
		mov eax, c; //c中存储的a的地址->eax 
		mov eax, [eax]; //a的值->eax
                        //注意直接mov eax, [c]是错误的
       	mov ebx, b; //可以像这样直接对ebx赋值
		lea eax, [eax+ebx];
		mov a, eax; //可以直接将eax的值->a
	} //内嵌汇编部分结束...
	cout<<a<<endl;
	


	__int64 time0=timestamp();
	for (int j=0;j<1000000;j++)
	{
		int a=10000;
	    a*=0.01;
	}
	//cout<<a<<endl;
	__int64 time00=timestamp()-time0;

	__int64 time1=timestamp();
	for (int i=0;i<1000000;i++)
	{
		int b=10000;
		b/=100;
	}
	//cout<<b<<endl;
	__int64 time10=timestamp()-time1;
	
	printf("乘浮点数的时间:%d\n",time00);
	printf("除整数的时间： %d\n",time10);
	//system("pause");
}
