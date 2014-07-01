#include <iostream>
using namespace std;

class Base
{
public:
	~Base();
};
Base::~Base()
{
	cout<<"Base::~Base()"<<endl;
}

class Derived: public Base
{
public:
	~Derived()
	{
		cout<<"Derived::~Derived()"<<endl;
	}
};

class Derived2: public Derived
{
public:
	~Derived2()
	{
		cout<<"Derived2::~Derived2"<<endl;
	}
};

int main()
{
	//如果析构函数不是虚函数，不能产生正确的析构函数调用
	Base *p = new Derived2;
	delete p;
	Derived *p1 = new Derived2;
	delete p1;
}
