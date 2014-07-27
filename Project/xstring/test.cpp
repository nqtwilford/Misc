#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "chs");
	wstring str = L"中";
	printf("%ls\n", str.c_str());
	return 0;
}

