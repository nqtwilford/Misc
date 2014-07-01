//继承中使用的virtual关键字与虚函数有着类似的原理，
//即使用指针来指向基类子对象，
//这样，在MI中可以保证只有一个基类子对象
#include <iostream>
using namespace std;

class Base
{
public:
	virtual char *vf() const =0;
};
char *Base::vf() const
{
	return "Base";
}

class Derived1: virtual public Base
{
public:
	virtual char *vf() const
	{
		return "Derived1";
	}
};

class Derived2: virtual public Base
{
public:
	virtual char *vf() const
	{
		return "Derived2";
	}
};

class MI: public Derived1, public Derived2
{
public:
	virtual char *vf() const
	{
		return "MI";
//		return Derived2::Base::vf();
	}
};

int main()
{
	MI obj;
//	Base &refBase = obj; 
	Derived2 &refDerived2 = obj;
	Base &refBase = refDerived2;
	cout<<refBase.vf()<<endl;
}
