#include <iostream>
#include <math.h>
using namespace std;

//int sign(int x)
//{
//	int lowbit = 0;
//	for(int i = 0; i < 32; ++i)
//	{
//		x = x>>1;
//		lowbit = x & 0x00000001 | lowbit;
//	}
//	return x | lowbit;
//}

int sign1(int x)
{
	int y = x | x>>16;
	y = y | y>>8;
	y = y | y>>4;
	y = y | y>>2;
	y = y | y>>1;
	y = y & 0x00000001;
	return x>>31 | y;
}

int sign(int x)
{
return (~(((x&0x80000000)&&1)-1) & 0xfffffffe) | ((x&0x7fffffff)&&1);
}

int main(int argc, char **argv)
{
	cout<<sign(45)<<" "<<sign(0)<<" "<<sign(-199)<<endl;
	cout<<sign(0x80000000)<<endl;
	return EXIT_SUCCESS;
}
