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

	//���������׽���
	cout<<"create socket..."<<endl;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == INVALID_SOCKET)
	{
		cerr<<"socket() failed:"<<WSAGetLastError()<<endl;
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;
	//����������ַ�ṹ
	addr.sin_family = AF_INET;
	addr.sin_port = htons(servport);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//���ӷ�����
	cout<<"connect..."<<endl;
	err = connect(sock, (SOCKADDR *)&addr, sizeof(addr));
	if(err != 0)
	{
		cerr<<"connect() failed:"<<WSAGetLastError()<<endl;
		closesocket(sock);
		return EXIT_FAILURE;
	}
	cout<<"[OK]"<<endl;

	//�ӷ�����������Ϣ
	cout<<"receive data..."<<endl;
	
	int ret = recv(sock, const_cast<char *>(buf.c_str()), 256, 0);
	if(ret == SOCKET_ERROR)
	{
		cerr<<"recv() failed."<<endl;
		return EXIT_FAILURE;
	}
	cout<<"receive "<<ret<<" bytes"<<endl;

	//������ܵ�����Ϣ
	cout<<buf.c_str()<<endl;

	//�ر��׽��֣��ͷ���Դ
	closesocket(sock);
	WSACleanup();
	return EXIT_SUCCESS;
}
