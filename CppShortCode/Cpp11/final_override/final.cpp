#include <iostream>
using namespace std;

class Base
{
public:
	virtual void func()
	{
		cout<<"Base::func()"<<endl;
	}
};

class Derived : public Base
{
public:
	virtual void func() final
	{
		cout<<"Derived::func()"<<endl;
	}
};

class Derived1 : public Derived
{
public:
	/*void func()	//Derived::func is final, can not override it
	{
		cout<<"Derived1::func()"<<endl;
	}*/
};

int main()
{
	Base *p = new Derived1;
	p->func();
	delete p;
	return 0;
}
