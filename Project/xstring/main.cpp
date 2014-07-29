#include "xstring.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "chs");
	/*
	const char *str = "中";
	size_t byteNum = getByteNum(str[0]);
	cout<<byteNum<<endl;
	std::wstring wstr = utf8ToWString(str);
	wprintf(L"%04X\n", (wstr[0]));
	wcout<<wstr<<endl;
	wprintf(L"%s\n", wstr.c_str());
	std::wstring wstr1 = L"中";
	wprintf(L"%04X\n", (wstr1[0]));
	wcout<<wstr1<<endl;
	wprintf(L"%s\n", wstr1.c_str());
	*/
	//*
	const char *str = "ABC中文123";
	std::wstring wstr = utf8ToWString(str);
	//wcout<<wstr<<endl;
	wprintf(L"%s\n", wstr.c_str());
	//*/
	/*std::wstring wstr1 = L"ABC中文123";
	printf("%ls\n", wstr1.c_str());
	wprintf(L"%ls\n", wstr1.c_str());*/
	return 0;
}
