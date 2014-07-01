#include <WINDOWS.H>
#include <iostream>
#include <STRING.H>
using namespace std;

HANDLE hOut;
HANDLE hIn;
void ClearScreen(void);
void DispMousePos(COORD pos); // �����һ����ʾ���λ��

int main()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼����豸���
	hIn = GetStdHandle(STD_INPUT_HANDLE); // ��ȡ��׼�����豸���
	
	//�������ô��ںͻ�������С
	COORD bufsize = {80, 25};
	SetConsoleScreenBufferSize(hOut,bufsize); // �������û�������С
	SMALL_RECT rcWnd = {0, 0, 80, 25}; // ���ô���λ�úʹ�С
	SetConsoleWindowInfo(hOut, true, &rcWnd);

	WORD att = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | 	
						 BACKGROUND_BLUE ;
	// ��������ɫ���ı���ɫ�ǻ�ɫ
	SetConsoleTextAttribute(hOut, att);
	ClearScreen(); // ����
	INPUT_RECORD mouseRec;
	DWORD state = 0, res;
	COORD pos = {0, 0};
	bool flag = false;
	for(;;) // ѭ��
	{
		ReadConsoleInput(hIn, &mouseRec, 2, &res);
		if (mouseRec.EventType == MOUSE_EVENT)
		{
//			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK) break;
			// ˫������˳�ѭ��
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
	SetConsoleCursorPosition(hOut, pos); // ���ù��λ��
	CloseHandle(hOut); // �رձ�׼����豸���
	CloseHandle(hIn); // �رձ�׼�����豸���
}

void DispMousePos(COORD pos) // �����һ����ʾ���λ��
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
	SetConsoleTextAttribute(hOut, bInfo.wAttributes); // �ָ�ԭ��������
	SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition); // �ָ�ԭ���Ĺ��λ��
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
