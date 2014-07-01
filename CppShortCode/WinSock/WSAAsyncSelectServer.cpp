#include <iostream>
#include <winsock2.h>
using namespace std;

#define WSAMSG WM_USER + 1

HWND hWnd;
SOCKET servsock;
const short SERVPORT = 9494;

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WSAMSG:
		if(servsock == wParam)
			cout<<"Message incoming"<<endl;
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void InitWnd()
{
	WNDCLASSEX wc =  { sizeof(WNDCLASSEX), CS_CLASSDC, 
		MsgProc, 0L, 0L, NULL, NULL, NULL, NULL, NULL, 
		"WSAAsyncWndClsServ", NULL };
	RegisterClassEx(&wc);
	hWnd = CreateWindow("WSAAsyncWndClsServ", "dummy", WS_POPUP,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, wc.hInstance, NULL);
}

bool InitServSock()
{
	//�����׽���
	cout<<"create socket..."<<endl;
	servsock = socket(AF_INET, SOCK_STREAM, 0);
	if(servsock == INVALID_SOCKET)
	{
		cerr<<"socket() failed:"<<WSAGetLastError()<<endl;
		return false;
	}
	cout<<"[OK]"<<endl;
	//���׽���
	SOCKADDR_IN servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERVPORT);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	cout<<"bind..."<<endl;
	if(bind(servsock, (SOCKADDR *)&servaddr, sizeof(servaddr)) != 0)
	{
		cerr<<"bind() failed:"<<WSAGetLastError()<<endl;
		closesocket(servsock);
		return false;
	}
	cout<<"[OK]"<<endl;
	//�����׽���
	cout<<"listen..."<<endl;
	if(listen(servsock, 5) != 0)
	{
		cerr<<"listen() failed:"<<WSAGetLastError()<<endl;
		closesocket(servsock);
		return false;
	}
	cout<<"[OK]"<<endl;
	return true;
}

int main(int argc, char **argv)
{
	//��ʼ��WinSock2.2
	WSADATA wsadata;
	if(WSAStartup(MAKEWORD(1,1), &wsadata) != 0)
	{
		cerr<<"WSAStartup() failed!"<<endl;
		return EXIT_FAILURE;
	}
	
	//��ʼ���������׽���
	if(!InitServSock())
		return EXIT_FAILURE;

	InitWnd();

	WSAAsyncSelect(servsock, hWnd, WSAMSG, FD_ACCEPT);

	MSG msg = {0};
	while(msg.message != WM_QUIT)
	{
		//��windowsӦ�ó����У�Ӧ��ʹ��GetMessage������
		//���������û��ȡ����Ϣ��ʱ�򲻻᷵�أ����Ա����˷�CPU��Դ
		//��DX�����У�Ӧʹ��PeekMessage�����������û��ȡ����Ϣ��ʱ��᷵�أ�
		//�������԰ѿ���ʱ�佻��DX��Ⱦ����������ô��˺������ᵼ��CPUռ���ʾӸ߲���
		if(GetMessage(&msg, NULL, 0U, 0U))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return EXIT_SUCCESS;
}
