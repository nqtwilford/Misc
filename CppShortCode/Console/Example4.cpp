#include <windows.h>
#include <iostream>
using namespace std;

HANDLE hOut;
void DeleteLine(int row); // ɾ��һ��
void MoveText(int x, int y, SMALL_RECT rc); // �ƶ��ı�������
void ClearScreen(void); // ����

int main()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼����豸���
	WORD att = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | 		
						 BACKGROUND_BLUE ;

	COORD bufsize = {80, 25};
	SetConsoleScreenBufferSize(hOut,bufsize); // �������û�������С
	SMALL_RECT rcWnd = {0, 0, 80, 25}; // ���ô���λ�úʹ�С
	SetConsoleWindowInfo(hOut, true, &rcWnd);
	// ��������ɫ���ı���ɫ�ǻ�ɫ
	SetConsoleTextAttribute(hOut, att);
	cout<<"fdasfsd"<<endl;
	system("pause");
	ClearScreen();
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &cci);
	COORD homePos= {0, 0};
	SetConsoleCursorPosition(hOut, homePos); // ���ù��λ��
	cout<<"\n\nThe soul selects her own society,\n";
	cout<<"Then shuts the door;\n";
	cout<<"On her devine majority;\n";
	cout<<"Obtrude no more.\n\n";
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo( hOut, &bInfo ); 
	COORD endPos = {0, bInfo.dwSize.Y-6};
	SetConsoleCursorPosition(hOut, endPos); // ���ù��λ��
	system("pause");
	SMALL_RECT rc = {0, 2, 40, 5};
	system("pause");
	MoveText(10, 5, rc);
	system("pause");
	DeleteLine(5);
	CloseHandle(hOut); // �رձ�׼����豸���
}

void DeleteLine(int row)
{
	SMALL_RECT rcScroll, rcClip;
	COORD crDest = {0, row - 1};
	CHAR_INFO chFill;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo( hOut, &bInfo ); 
	rcScroll.Left = 0;
	rcScroll.Top = row;
	rcScroll.Right = bInfo.dwSize.X - 1;
	rcScroll.Bottom = bInfo.dwSize.Y - 1;
	rcClip = rcScroll;
	chFill.Attributes = bInfo.wAttributes;
	chFill.Char.AsciiChar = ' ';
	ScrollConsoleScreenBuffer(hOut, &rcScroll, &rcClip, crDest, &chFill);
}

void MoveText(int x, int y, SMALL_RECT rc)
{
	COORD crDest = {x, y};
	CHAR_INFO chFill;
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo( hOut, &bInfo ); 
	chFill.Attributes = bInfo.wAttributes;
	chFill.Char.AsciiChar = ' ';
	ScrollConsoleScreenBuffer(hOut, &rc, NULL, crDest, &chFill);
}

void ClearScreen(void)
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo( hOut, &bInfo ); 
	COORD home = {0, 0};
	WORD att = bInfo.wAttributes;
	unsigned long size = bInfo.dwSize.X * bInfo.dwSize.Y;
	FillConsoleOutputAttribute(hOut, att, size, home, NULL);
	FillConsoleOutputCharacter(hOut, ' ', size, home, NULL);
}
