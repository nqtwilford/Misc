#include <iostream>
#include <sstream>
#include <winsock2.h>
using namespace std;

int main(int argc, char *argv[])
{
	SOCKET servsock, clisock;
	SOCKADDR_IN servaddr;
	SOCKADDR_IN cliaddr;
	int len;
	int err;
	short servport = 9494;
	SYSTEMTIME systime;
	WSADATA wsadata;

	//初始化WinSock2.2
	if(WSAStartup(MAKEWORD(1,1), &wsadata) != 0)
	{
		cerr<<"WSAStartup() failed!"<<endl;
		return EXIT_FAILURE;
	}

	//创建套接字
	cout<<"create socket..."<<endl;
	servsock = socket(AF_INET, SOCK_STREAM, 0);
	if(servsock == INVALID_SOCKET)
	{
		cerr<<"socket() failed:"<<WSAGetLastError()<<endl;
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;
	//绑定套接字
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(servport);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	cout<<"bind..."<<endl;
	err = bind(servsock, (SOCKADDR *)&servaddr, sizeof(servaddr));
	if(err != 0)
	{
		cerr<<"bind() failed:"<<WSAGetLastError()<<endl;
		closesocket(servsock);
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;
	//监听套接字
	cout<<"listen..."<<endl;
	err = listen(servsock, 5);
	if(err != 0)
	{
		cerr<<"listen() failed:"<<WSAGetLastError()<<endl;
		closesocket(servsock);
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;
	//接受客户端连接请求
	while(true)
	{
		cout<<"wait request..."<<endl;
		len = sizeof(cliaddr);
		clisock = accept(servsock, (SOCKADDR *)&cliaddr, &len);
		if(clisock == INVALID_SOCKET)
		{
			cerr<<"accept() failed:"<<WSAGetLastError()<<endl;
			closesocket(servsock);
			return EXIT_FAILURE;
		}
		cout<<"accept client:"<<inet_ntoa(cliaddr.sin_addr)<<":"<<ntohs(cliaddr.sin_port)<<endl;
		//取得服务器时间
		GetLocalTime(&systime);
		ostringstream os;
		os<<systime.wYear<<"-"<<systime.wMonth<<"-"<<systime.wDay<<" ";
		os<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<ends;
		int ret = send(clisock, os.str().c_str(), os.str().size(), 0);
		if(ret == SOCKET_ERROR)
		{
			cerr<<"send failed."<<endl;
		}
		else
		{
			cout<<"send "<<ret<<" bytes."<<endl;
		}
		closesocket(clisock);
		
	}
	closesocket(servsock);
	WSACleanup();
	return EXIT_SUCCESS;
}
