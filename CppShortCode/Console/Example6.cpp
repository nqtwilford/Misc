#include <WINDOWS.H>
#include <iostream>
#include <STRING.H>
using namespace std;

HANDLE hOut;
HANDLE hIn;
void ClearScreen(void);
void DispMousePos(COORD pos); // 在最后一行显示鼠标位置

int main()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄
	hIn = GetStdHandle(STD_INPUT_HANDLE); // 获取标准输入设备句柄
	
	//重新设置窗口和缓冲区大小
	COORD bufsize = {80, 25};
	SetConsoleScreenBufferSize(hOut,bufsize); // 重新设置缓冲区大小
	SMALL_RECT rcWnd = {0, 0, 80, 25}; // 重置窗口位置和大小
	SetConsoleWindowInfo(hOut, true, &rcWnd);

	WORD att = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | 	
						 BACKGROUND_BLUE ;
	// 背景是蓝色，文本颜色是黄色
	SetConsoleTextAttribute(hOut, att);
	ClearScreen(); // 清屏
	INPUT_RECORD mouseRec;
	DWORD state = 0, res;
	COORD pos = {0, 0};
	bool flag = false;
	for(;;) // 循环
	{
		ReadConsoleInput(hIn, &mouseRec, 2, &res);
		if (mouseRec.EventType == MOUSE_EVENT)
		{
//			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK) break;
			// 双击鼠标退出循环
			pos = mouseRec.Event.MouseEvent.dwMousePosition;
			DispMousePos(pos);
			SetConsoleCursorPosition(hOut, pos);
			if (mouseRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				if(flag)
				{
					FillConsoleOutputCharacter(hOut, 'A', 1, pos, NULL); 
					flag = false;
				}
				else
				{
					FillConsoleOutputCharacter(hOut, ' ', 1, pos, NULL);
					flag = true;
				}
			}
		}
	} 
	pos.X = 0; pos.Y = 0;
	SetConsoleCursorPosition(hOut, pos); // 设置光标位置
	CloseHandle(hOut); // 关闭标准输出设备句柄
	CloseHandle(hIn); // 关闭标准输入设备句柄
}

void DispMousePos(COORD pos) // 在最后一行显示鼠标位置
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo( hOut, &bInfo ); 
	COORD home = {0, bInfo.dwSize.Y-1};
	WORD att0 = BACKGROUND_INTENSITY ;
	FillConsoleOutputAttribute(hOut, att0, bInfo.dwSize.X, home, NULL);
	FillConsoleOutputCharacter(hOut, ' ', bInfo.dwSize.X, home, NULL);
	char s[20];
	sprintf(s,"X = %2lu, Y = %2lu",pos.X, pos.Y);
	SetConsoleTextAttribute(hOut, att0);
	SetConsoleCursorPosition(hOut, home);
	WriteConsole(hOut, s, strlen(s), NULL, NULL);
	SetConsoleTextAttribute(hOut, bInfo.wAttributes); // 恢复原来的属性
	SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition); // 恢复原来的光标位置
}

void ClearScreen(void)
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo( hOut, &bInfo ); 
	COORD home = {0, 0};
	unsigned long size = bInfo.dwSize.X * bInfo.dwSize.Y;
	FillConsoleOutputAttribute(hOut, bInfo.wAttributes, size, home, NULL);
	FillConsoleOutputCharacter(hOut, ' ', size, home, NULL);
}
