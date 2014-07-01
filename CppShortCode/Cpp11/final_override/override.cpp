#include <iostream>
using namespace std;

class Base
{
public:
	virtual void function()
	{
		cout<<"Base::function()"<<endl;
	}
};

class Derived : public Base
{
public:
	void funtion() override		//compile error: spell mistake, override nothing
	{
		cout<<"Derived::function()"<<endl;
	}
};

int main()
{
	Base *p = new Derived;
	p->function();
	delete p;
	return 0;
}
