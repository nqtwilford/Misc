#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	cout<<"fsdfsdfs"<<endl;
	system("pause");
	COORD pos = {0, 0};
	FillConsoleOutputCharacter(hOut, ' ', bInfo.dwSize.X * bInfo.dwSize.Y, pos, NULL);

	CloseHandle(hOut);
}
