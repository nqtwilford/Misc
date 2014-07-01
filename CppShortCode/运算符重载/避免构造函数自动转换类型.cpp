#include <iostream>
using namespace std;

class X
{
public:
	X(){}
	//使用该构造函数不会自动转换类型
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
