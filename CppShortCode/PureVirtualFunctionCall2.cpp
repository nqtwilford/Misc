#include <iostream>
using namespace std;

class Base
{
public:
	virtual void func() = 0;
};

class B : public Base
{
public:
	virtual void func()
	{}
};

class A
{
public:
	A(B *p):m_pB(p){}
	~A()
	{
		m_pB->func();
	}
private:
	B *m_pB;
};

//��ĳЩ�������£�b��������a����
B b;
A a(&b);

int main(int argc, char **argv)
{
	return EXIT_SUCCESS;
}
