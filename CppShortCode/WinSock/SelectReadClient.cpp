#include <iostream>
#include <winsock2.h>
using namespace std;

const char *SERVIP = "127.0.0.1";
const short SERVPORT = 9494;
const size_t BUFSIZE = 256;
char buf[BUFSIZE] = {0};

int main(int argc, char **argv)
{
	//��ʼ��WinSock2.2
	WSADATA wsadata;
	if(WSAStartup(MAKEWORD(1,1), &wsadata) != 0)
	{
		cerr<<"WSAStartup() failed!"<<endl;
		return EXIT_FAILURE;
	}

	//�����׽���
	cout<<"create socket..."<<endl;
	SOCKET servsock;
	servsock = socket(AF_INET, SOCK_STREAM, 0);
	if(servsock == INVALID_SOCKET)
	{
		cerr<<"socket() failed:"<<WSAGetLastError()<<endl;
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;
	//���ӷ�����
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
	//����select�����������׽����Ƿ���Զ�ȡ����
	while(true)
	{
		cout<<"check readable socket..."<<endl;
		FD_SET fdrd;	//�ɶ�ȡ�׽��ּ�
		FD_ZERO(&fdrd);
		FD_SET(servsock, &fdrd);
		TIMEVAL timeout = {1, 0};	//�ȴ�1��
		int ret = select(0, &fdrd, NULL, NULL, &timeout);
		if(ret == SOCKET_ERROR)
		{
			cerr<<"select() failed:"<<WSAGetLastError()<<endl;
			closesocket(servsock);
			return EXIT_FAILURE;
		}
		cout<<ret<<endl;
		//�ж�servsock�Ƿ��ڿɶ�sock��
		if(ret > 0 && FD_ISSET(servsock, &fdrd))
		{
			memset(buf, 0, BUFSIZE);
			int bytes = recv(servsock, buf, BUFSIZE, 0);
			if(bytes == SOCKET_ERROR)
			{
				cerr<<"recv() failed:"<<WSAGetLastError()<<endl;
				closesocket(servsock);
				return EXIT_FAILURE;
			}
			cout<<bytes<<" bytes received..."<<endl;
			cout<<buf<<endl;
		}
		else
		{
			cout<<"not yet readable now, try again later..."<<endl;
		}
		Sleep(2000);
	}
	closesocket(servsock);
	return EXIT_SUCCESS;
}
