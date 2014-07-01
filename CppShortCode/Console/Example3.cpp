#include <windows.h>
#include <iostream>
using namespace std;

HANDLE hOut;
void ShadowWindowLine(char *str); // �ھ�����ӰЧ���Ĵ�������ʾһ���ַ�������Ϊ������ʾ
void DrawBox(bool bSingle, SMALL_RECT rc); // ���Ʊ߿�
int main()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼����豸���
	SetConsoleOutputCP(437); // ���ô���ҳ
	ShadowWindowLine("Display a line of words, and center the window with shadow.");
	system("pause");
	CloseHandle(hOut); // �رձ�׼����豸���
}

void ShadowWindowLine(char *str)
{
	COORD bufsize = {80, 25};
	SetConsoleScreenBufferSize(hOut,bufsize); // �������û�������С
	SMALL_RECT rcWnd = {0,0, 80, 25}; // ���ô���λ�úʹ�С
	SetConsoleWindowInfo(hOut, true, &rcWnd);

	CONSOLE_SCREEN_BUFFER_INFO bInfo; // ���ڻ�������Ϣ
	GetConsoleScreenBufferInfo( hOut, &bInfo ); // ��ȡ���ڻ�������Ϣ
	
	// ������ʾ���ڴ�С��λ��
	int x1, y1, x2, y2, chNum = strlen(str);
	x1 = (bInfo.dwSize.X - chNum)/2 - 2;
	y1 = bInfo.dwSize.Y/2 - 2;
	x2 = x1 + chNum + 4;
	y2 = y1 + 5;
	
	WORD att1 = BACKGROUND_INTENSITY; // ��Ӱ����
	WORD att0 = FOREGROUND_RED |FOREGROUND_GREEN |FOREGROUND_BLUE | 	
				FOREGROUND_INTENSITY |BACKGROUND_RED | BACKGROUND_BLUE; // �ı�����

	WORD attText = FOREGROUND_RED |FOREGROUND_INTENSITY; // �ı�����
	// ������Ӱ
	COORD posShadow = {x1+1, y1+1}, posText = {x1, y1};
	for (int i=0; i<5; i++){
		FillConsoleOutputAttribute(hOut, att1, chNum + 4, posShadow, NULL); 
		posShadow.Y++;
	}
	// ��䴰�ڱ���
	for (int i=0; i<5; i++){
		FillConsoleOutputAttribute(hOut, att0, chNum + 4, posText, NULL); 
		posText.Y++;
	}
	// д�ı��ͱ߿�
	posText.X = x1 + 2;
	posText.Y = y1 + 2;
	WriteConsoleOutputCharacter(hOut, str, strlen(str), posText, NULL);
	SMALL_RECT rc = {x1, y1, x2-1, y2-1};
	DrawBox(true, rc);
	SetConsoleTextAttribute(hOut, bInfo.wAttributes); // �ָ�ԭ��������
}

void DrawBox(bool bSingle, SMALL_RECT rc)
{
	char chBox[6];
	if (bSingle) 
	{
		chBox[0] = (char)0xda; // ���Ͻǵ�
		chBox[1] = (char)0xbf; // ���Ͻǵ�
		chBox[2] = (char)0xc0; // ���½ǵ�
		chBox[3] = (char)0xd9; // ���½ǵ�
		chBox[4] = (char)0xc4; // ˮƽ
		chBox[5] = (char)0xb3; // ��ֱ
	} 
	else 
	{
		chBox[0] = (char)0xc9; // ���Ͻǵ�
		chBox[1] = (char)0xbb; // ���Ͻǵ�
		chBox[2] = (char)0xc8; // ���½ǵ�
		chBox[3] = (char)0xbc; // ���½ǵ�
		chBox[4] = (char)0xcd; // ˮƽ
		chBox[5] = (char)0xba; // ��ֱ
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
