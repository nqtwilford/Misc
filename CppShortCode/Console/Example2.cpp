#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	// 获取标准输出设备句柄
	CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口缓冲区信息
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	// 获取窗口缓冲区信息
	char strTitle[255];
	GetConsoleTitle(strTitle, 255); // 获取窗口标题
//	printf("当前窗口标题是：%s\n", strTitle);
	cout<<"当前窗口标题是："<<strTitle<<endl;
	system("pause");
	SetConsoleTitle("控制台窗口操作"); // 获取窗口标题
	system("pause");
	COORD size = {8, 5};
	SetConsoleScreenBufferSize(hOut,size); // 重新设置缓冲区大小
	system("pause");
	SMALL_RECT rc = {0,0, 80-10, 25-10}; // 重置窗口位置和大小
	SetConsoleWindowInfo(hOut,true ,&rc);
	system("pause");
	//修改文本属性
	COORD pos = {3,2};
	FillConsoleOutputAttribute(hOut, BACKGROUND_BLUE, 10, pos, NULL);
	system("pause");
	//设置今后的输出属性
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	cout<<"文字是不是变红了呢"<<endl;
	system("pause");
//	pos.X = 3;
//	pos.Y = 3;
	WORD attr = BACKGROUND_BLUE;
	WriteConsoleOutputAttribute(hOut, &attr, 10, pos, NULL);
	CloseHandle(hOut); // 关闭标准输出设备句柄
	return 0;
}
