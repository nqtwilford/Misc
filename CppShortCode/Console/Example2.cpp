#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	// ��ȡ��׼����豸���
	CONSOLE_SCREEN_BUFFER_INFO bInfo; // ���ڻ�������Ϣ
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	// ��ȡ���ڻ�������Ϣ
	char strTitle[255];
	GetConsoleTitle(strTitle, 255); // ��ȡ���ڱ���
//	printf("��ǰ���ڱ����ǣ�%s\n", strTitle);
	cout<<"��ǰ���ڱ����ǣ�"<<strTitle<<endl;
	system("pause");
	SetConsoleTitle("����̨���ڲ���"); // ��ȡ���ڱ���
	system("pause");
	COORD size = {8, 5};
	SetConsoleScreenBufferSize(hOut,size); // �������û�������С
	system("pause");
	SMALL_RECT rc = {0,0, 80-10, 25-10}; // ���ô���λ�úʹ�С
	SetConsoleWindowInfo(hOut,true ,&rc);
	system("pause");
	//�޸��ı�����
	COORD pos = {3,2};
	FillConsoleOutputAttribute(hOut, BACKGROUND_BLUE, 10, pos, NULL);
	system("pause");
	//���ý����������
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	cout<<"�����ǲ��Ǳ������"<<endl;
	system("pause");
//	pos.X = 3;
//	pos.Y = 3;
	WORD attr = BACKGROUND_BLUE;
	WriteConsoleOutputAttribute(hOut, &attr, 10, pos, NULL);
	CloseHandle(hOut); // �رձ�׼����豸���
	return 0;
}
