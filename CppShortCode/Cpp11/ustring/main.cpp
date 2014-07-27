#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void HexPrint(const void *buf, size_t len)
{
	for(size_t i = 0; i < len; ++i)
	{
		unsigned char c = ((const char *)buf)[i];
		printf("%02X ", c);
	}
	printf("\n");
}

void HexPrintStr(const char *str)
{
	HexPrint(str, strlen(str));
}

int main()
{
	const char *strA = "中";
	HexPrintStr(strA);
	printf(strA);
	
	//const char16_t *stru = u"中";
	//cout<<strlen((const char *)stru)<<endl;

	return 0;
}
