//一个手动调用虚函数的例子，理解虚函数表
#include <iostream>
using namespace std;

class Base
{
public:
	Base(int i):m_i(i){}
	virtual void fun1(int h) {cout<<"Base::fun1() "<<m_i<<" "<<h<<endl;}
protected:
	int m_i;
};

class A:public Base
{
public:
	A(int i, int j):Base(i), m_j(j){}
	void fun1(int h) {cout<<"A::fun1() "<<m_j<<" "<<h<<endl;}
private:
	int m_j;
};

void foo (Base& obj)
{
	typedef void (*FUNC)(Base *, int);
	int *vptr = (int *)*(int *)&obj;
	FUNC fun = (FUNC)vptr[0];
	fun(&obj, 99);
}

int main()
{
	Base b(1);
	A a(2, 3);
	foo(b);
	foo(a);
	return 0;
}
