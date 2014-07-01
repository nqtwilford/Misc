#include <windows.h>
#include <iostream>
using namespace std;

HANDLE hOut;
void ShadowWindowLine(char *str); // 在具有阴影效果的窗口中显示一行字符，窗口为居中显示
void DrawBox(bool bSingle, SMALL_RECT rc); // 绘制边框
int main()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄
	SetConsoleOutputCP(437); // 设置代码页
	ShadowWindowLine("Display a line of words, and center the window with shadow.");
	system("pause");
	CloseHandle(hOut); // 关闭标准输出设备句柄
}

void ShadowWindowLine(char *str)
{
	COORD bufsize = {80, 25};
	SetConsoleScreenBufferSize(hOut,bufsize); // 重新设置缓冲区大小
	SMALL_RECT rcWnd = {0,0, 80, 25}; // 重置窗口位置和大小
	SetConsoleWindowInfo(hOut, true, &rcWnd);

	CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口缓冲区信息
	GetConsoleScreenBufferInfo( hOut, &bInfo ); // 获取窗口缓冲区信息
	
	// 计算显示窗口大小和位置
	int x1, y1, x2, y2, chNum = strlen(str);
	x1 = (bInfo.dwSize.X - chNum)/2 - 2;
	y1 = bInfo.dwSize.Y/2 - 2;
	x2 = x1 + chNum + 4;
	y2 = y1 + 5;
	
	WORD att1 = BACKGROUND_INTENSITY; // 阴影属性
	WORD att0 = FOREGROUND_RED |FOREGROUND_GREEN |FOREGROUND_BLUE | 	
				FOREGROUND_INTENSITY |BACKGROUND_RED | BACKGROUND_BLUE; // 文本属性

	WORD attText = FOREGROUND_RED |FOREGROUND_INTENSITY; // 文本属性
	// 设置阴影
	COORD posShadow = {x1+1, y1+1}, posText = {x1, y1};
	for (int i=0; i<5; i++){
		FillConsoleOutputAttribute(hOut, att1, chNum + 4, posShadow, NULL); 
		posShadow.Y++;
	}
	// 填充窗口背景
	for (int i=0; i<5; i++){
		FillConsoleOutputAttribute(hOut, att0, chNum + 4, posText, NULL); 
		posText.Y++;
	}
	// 写文本和边框
	posText.X = x1 + 2;
	posText.Y = y1 + 2;
	WriteConsoleOutputCharacter(hOut, str, strlen(str), posText, NULL);
	SMALL_RECT rc = {x1, y1, x2-1, y2-1};
	DrawBox(true, rc);
	SetConsoleTextAttribute(hOut, bInfo.wAttributes); // 恢复原来的属性
}

void DrawBox(bool bSingle, SMALL_RECT rc)
{
	char chBox[6];
	if (bSingle) 
	{
		chBox[0] = (char)0xda; // 左上角点
		chBox[1] = (char)0xbf; // 右上角点
		chBox[2] = (char)0xc0; // 左下角点
		chBox[3] = (char)0xd9; // 右下角点
		chBox[4] = (char)0xc4; // 水平
		chBox[5] = (char)0xb3; // 坚直
	} 
	else 
	{
		chBox[0] = (char)0xc9; // 左上角点
		chBox[1] = (char)0xbb; // 右上角点
		chBox[2] = (char)0xc8; // 左下角点
		chBox[3] = (char)0xbc; // 右下角点
		chBox[4] = (char)0xcd; // 水平
		chBox[5] = (char)0xba; // 坚直
	}
	COORD pos = {rc.Left, rc.Top};
	WriteConsoleOutputCharacter(hOut, &chBox[0], 1, pos, NULL);

	for(pos.X = rc.Left + 1; pos.X < rc.Right; ++pos.X)
		WriteConsoleOutputCharacter(hOut, &chBox[4], 1, pos, NULL);

	pos.X = rc.Right;
	WriteConsoleOutputCharacter(hOut, &chBox[1], 1, pos, NULL);

	for (pos.Y = rc.Top+1; pos.Y < rc.Bottom; ++pos.Y)
	{
		pos.X = rc.Left;
		WriteConsoleOutputCharacter(hOut, &chBox[5], 1, pos, NULL);
		pos.X = rc.Right;
		WriteConsoleOutputCharacter(hOut, &chBox[5], 1, pos, NULL);
	}
	pos.X = rc.Left; pos.Y = rc.Bottom;
	WriteConsoleOutputCharacter(hOut, &chBox[2], 1, pos, NULL);
	
	for (pos.X = rc.Left + 1; pos.X	< rc.Right; ++pos.X)	
		WriteConsoleOutputCharacter(hOut, &chBox[4], 1, pos, NULL);

	pos.X = rc.Right;
	WriteConsoleOutputCharacter(hOut, &chBox[3], 1, pos, NULL);
}
