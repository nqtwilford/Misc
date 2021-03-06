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
		"WSAAsyncWndClsClient", NULL };
	RegisterClassEx(&wc);
	hWnd = CreateWindow("WSAAsyncWndClsClient", "dummy", WS_POPUP,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, wc.hInstance, NULL);
}

bool InitServSock()
{
	//创建套接字
	cout<<"create socket..."<<endl;
	servsock = socket(AF_INET, SOCK_STREAM, 0);
	if(servsock == INVALID_SOCKET)
	{
		cerr<<"socket() failed:"<<WSAGetLastError()<<endl;
		return false;
	}
	cout<<"[OK]"<<endl;
	return true;
}

int main(int argc, char **argv)
{
	//初始化WinSock2.2
	WSADATA wsadata;
	if(WSAStartup(MAKEWORD(1,1), &wsadata) != 0)
	{
		cerr<<"WSAStartup() failed!"<<endl;
		return EXIT_FAILURE;
	}
	
	//初始化服务器套接字
	if(!InitServSock())
		return EXIT_FAILURE;

	//连接服务器
	cout<<"connect..."<<endl;
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(SERVPORT);
	addr.sin_addr.s_addr = inet_addr(SERVIP);
	if(connect(servsock, (SOCKADDR *)&addr, sizeof(addr)) != 0)
	{
		cerr<<"connect() failed:"<<WSAGetLastError()<<endl;
		closesocket(servsock);
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;

	WSAAsyncSelect(servsock, hWnd, WSAMSG, FD_ACCEPT);

	MSG msg = {0};
	while(msg.message != WM_QUIT)
	{
		//在windows应用程序中，应该使用GetMessage函数，
		//这个函数在没有取到消息的时候不会返回，可以避免浪费CPU资源
		//在DX程序中，应使用PeekMessage，这个函数在没有取到消息的时候会返回，
		//这样可以把空闲时间交给DX渲染。如果这里用错了函数，会导致CPU占用率居高不下
		if(GetMessage(&msg, NULL, 0U, 0U))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return EXIT_SUCCESS;
}
