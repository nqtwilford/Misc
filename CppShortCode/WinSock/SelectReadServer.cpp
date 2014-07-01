#include <iostream>
#include <sstream>
#include <winsock2.h>
using namespace std;

const short servport = 9494;

int main(int argc, char **argv)
{
	//初始化WinSock2.2
	WSADATA wsadata;
	if(WSAStartup(MAKEWORD(1,1), &wsadata) != 0)
	{
		cerr<<"WSAStartup() failed!"<<endl;
		return EXIT_FAILURE;
	}

	//创建套接字
	cout<<"create socket..."<<endl;
	SOCKET servsock = socket(AF_INET, SOCK_STREAM, 0);
	if(servsock == INVALID_SOCKET)
	{
		cerr<<"socket() failed:"<<WSAGetLastError()<<endl;
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;
	//绑定套接字
	SOCKADDR_IN servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(servport);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	cout<<"bind..."<<endl;
	if(bind(servsock, (SOCKADDR *)&servaddr, sizeof(servaddr)) != 0)
	{
		cerr<<"bind() failed:"<<WSAGetLastError()<<endl;
		closesocket(servsock);
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;
	//监听套接字
	cout<<"listen..."<<endl;
	if(listen(servsock, 5) != 0)
	{
		cerr<<"listen() failed:"<<WSAGetLastError()<<endl;
		closesocket(servsock);
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;
	//等待客户端连接
	while(true)
	{
		cout<<"wait request..."<<endl;
		//检查是否有客户请求
		FD_SET fdrd;
		FD_ZERO(&fdrd);
		FD_SET(servsock, &fdrd);
		TIMEVAL timeout = {1, 0};
		int ret = select(0, &fdrd, NULL, NULL, &timeout);
		if(ret == SOCKET_ERROR)
		{
			cerr<<"select() failed:"<<WSAGetLastError()<<endl;
			closesocket(servsock);
			return EXIT_FAILURE;
		}
		//判断servsock是否在可读sock内
		if(ret > 0 && FD_ISSET(servsock, &fdrd))
		{
			SOCKADDR_IN cliaddr;
			int len = sizeof(cliaddr);
			SOCKET clisock = accept(servsock, (SOCKADDR *)&cliaddr, &len);
			if(clisock == INVALID_SOCKET)
			{
				cerr<<"accept() failed:"<<WSAGetLastError()<<endl;
				closesocket(servsock);
				return EXIT_FAILURE;
			}
			cout<<"accept client:"<<inet_ntoa(cliaddr.sin_addr)<<":"<<ntohs(cliaddr.sin_port)<<endl;

			system("pause");
			//向客户发送信息
			hostent *host = gethostbyaddr((char *)&cliaddr.sin_addr, sizeof(cliaddr), AF_INET);
			ostringstream os;
			os<<"你好"<<"Welcome, "<<host->h_name<<"!"<<ends;
			int ret = send(clisock, os.str().c_str(), os.str().size(), 0);
			if(ret == SOCKET_ERROR)
			{
				cerr<<"send failed."<<endl;
			}
			else
			{
				cout<<"send "<<ret<<" bytes."<<endl;
			}
			system("pause");
			shutdown(clisock, SD_BOTH);
		}
		else
		{
			cout<<"no request now..."<<endl;
		}
		Sleep(2000);
	}
	return EXIT_SUCCESS;
}
