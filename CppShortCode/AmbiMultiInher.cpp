#include <iostream>
using namespace std;

class Base
{
public:
	virtual char *vf() const =0;
};

class Derived1: public Base
{
public:
	virtual char *vf() const
	{
		return "Derived1";
	}
};

class Derived2: public Base
{
public:
	virtual char *vf() const
	{
		return "Derived2";
	}
};

class MI: public Derived1, public Derived2
{
//public:
//	virtual char *vf() const
//	{
//		return "MI";
//	}
};

int main()
{
	MI obj;
	cout<<obj.vf()<<endl;
	Derived2 &ref = obj;
	Base &ref2 = ref;
	cout<<ref2.vf()<<endl;
}
