#include <iostream>
using namespace std;

class X
{
public:
	X(){}
	//ʹ�øù��캯�������Զ�ת������
	explicit X(int i){}
};

void f(X)
{
}

int main(int argc, char *argv[])
{
	f(3);
	return 0;
}
