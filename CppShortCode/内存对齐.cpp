#include <iostream>
#include "G:\MyUtil\include\MyUtil.h"
using namespace std;

//请尝试不同的对齐方式
#pragma pack(2)
struct C{
	C():a(1), b(2), c(3), d(4){}
 double a;
 short b;
 int c;
 char d;
}; 

int main(int argc, char **argv)
{
	cout<<sizeof(C)<<endl;
	C obj;
	char *p = (char *)&obj;
	for(int i = 0; i < sizeof(C); ++i)
	{
		cout<<bin(p[i])<<" ";
	}
	cout<<endl;
	return EXIT_SUCCESS;
}
