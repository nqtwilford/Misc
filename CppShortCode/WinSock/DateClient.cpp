#include <iostream>
#include <sstream>
#include <winsock2.h>
using namespace std;

int main(int argc, char **argv)
{
	SOCKET sock;
	SOCKADDR_IN addr;
	int err;
	short servport = 9494;
	WSADATA wsadata;
	string buf(256, '\0');
	
	if(WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
	{
		cerr<<"WSAStartup() failed"<<endl;
		return EXIT_FAILURE;
	}

	//创建连接套接字
	cout<<"create socket..."<<endl;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == INVALID_SOCKET)
	{
		cerr<<"socket() failed:"<<WSAGetLastError()<<endl;
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;
	//填充服务器地址结构
	addr.sin_family = AF_INET;
	addr.sin_port = htons(servport);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//连接服务器
	cout<<"connect..."<<endl;
	err = connect(sock, (SOCKADDR *)&addr, sizeof(addr));
	if(err != 0)
	{
		cerr<<"connect() failed:"<<WSAGetLastError()<<endl;
		closesocket(sock);
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;

	//从服务器接受信息
	cout<<"receive data..."<<endl;
	
	int ret = recv(sock, const_cast<char *>(buf.c_str()), 256, 0);
	if(ret == SOCKET_ERROR)
	{
		cerr<<"recv() failed."<<endl;
		return EXIT_FAILURE;
	}
	cout<<"receive "<<ret<<" bytes"<<endl;

	//输出接受到的信息
	cout<<buf.c_str()<<endl;

	//关闭套接字，释放资源
	closesocket(sock);
	WSACleanup();
	return EXIT_SUCCESS;
}
