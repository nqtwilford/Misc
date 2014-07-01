#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	cout<<"fsdfas"<<endl;

	Sleep(3000);

	HANDLE  hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD hWrittenChars = 0;
	CONSOLE_SCREEN_BUFFER_INFO strConsoleInfo;
	COORD Home;

	GetConsoleScreenBufferInfo(hConsoleHandle, &strConsoleInfo);
	FillConsoleOutputCharacter(hConsoleHandle, '\0', strConsoleInfo.dwSize.X * strConsoleInfo.dwSize.Y, Home, &hWrittenChars);
	SetConsoleCursorPosition(hConsoleHandle, Home);

}
