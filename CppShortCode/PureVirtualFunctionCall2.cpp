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

//在某些编译器下，b可能先于a销毁
B b;
A a(&b);

int main(int argc, char **argv)
{
	return EXIT_SUCCESS;
}
