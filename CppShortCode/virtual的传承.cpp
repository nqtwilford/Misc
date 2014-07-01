#include <iostream>
using namespace std;

class Base
{
public:
	virtual void f()
	{
		cout<<"Base::f()"<<endl;
	}
};

class Derived1: public Base
{
public:
	void f()
	{
		cout<<"Derived1::f()"<<endl;
	}
};

class Derived2: public Derived1
{
public:
	void f()
	{
		cout<<"Derived2::f()"<<endl;
	}
};

int main()
{
	Derived2 d2;
	Derived1 *pD1 = &d2;
	pD1->f();		//在Derived1中f()虽然没有声明virtual关键字，但仍然为虚函数
}
