#include <stdio.h>
#include <string>
#include "xstring.h"
using namespace std;

int main()
{
	/*
	setlocale(LC_ALL, "chs");
	wstring str = L"中";
	printf("%ls\n", str.c_str());
	*/
	for(int mask : masksUnicode)
	{
		printf("0x%08X\n", mask);
	}
	return 0;
}

