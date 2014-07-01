//纯虚函数也可以有定义，但是仍然不能实例化，它只能提供给子类使用
#include <iostream>
using namespace std;

class PureAbstract
{
public:
	virtual void f() = 0;
};

void PureAbstract::f()
{
	cout<<"PureAbstract::f()"<<endl;
}

class Concrete: public PureAbstract
{
public:
	virtual void f()
	{
		cout<<"Concrete::f()"<<endl;
		PureAbstract::f();
	}
};

int main()
{
//	PureAbstract obj1;
	Concrete obj;
	obj.f();
}
