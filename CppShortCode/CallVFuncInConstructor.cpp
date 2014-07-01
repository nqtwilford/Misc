#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		f();	//this will call Base::f() or the Derived::f()
	}
	virtual void f()
	{
		cout<<"Base::f()"<<endl;
		g();
	}
	virtual void g()
	{
		cout<<"Base::g()"<<endl;
	}
};

class Derived: public Base
{
public:
	virtual void f()
	{
		cout<<"Derived::f()"<<endl;
		g();
	}
	virtual void g()
	{
		cout<<"Derived::g()"<<endl;
	}
};

int main()
{
	Derived d;	//Base::f()将会被调用，因为在基类构造的时候，派生类尚未构造
				//如果调用Derived::f()，将导致访问未初始化的成员
				//同理，在析构函数中，也只有本地版本函数被调用，因为派生类已经销毁
				//如果调用派生类函数，同样会造成非法操作
	system("pause");
	return 0;
}
