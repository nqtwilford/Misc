#include <iostream>
#include <fstream>
#include "Vendor.h"
using namespace std;

ofstream out("Fixing.txt");

class MyBase	//Repair Vendor interface
{
public:
	virtual void v() const = 0;
	virtual void f() const = 0;
	//New interface function:
	virtual void g() const = 0;
	virtual ~MyBase()
	{
		out<<"~MyBase()\n";
	}
};

class Fixing : public MyBase, public Vendor1
{
public:
	void v() const
	{
		out<<"Fixing::v()\n";
		Vendor1::v();
	}
	void f() const
	{
		out<<"Fixing::f()\n";
		Vendor1::f();
	}
	void g() const
	{
		out<<"Fixing::g()\n";
	}
	~Fixing()
	{
		out<<"~Fixing()\n";
	}
};

int main()
{
	Fixing &fx = *new Fixing;
	MyBase &mb = fx;
	out<<"calling f()\n";
	mb.f();
	out<<"calling g()\n";
	mb.g();
	out<<"calling A(fx)\n";
	A(fx);
	out<<"calling B(fx)\n";
	B(fx);
	out<<"delete mb\n";
	delete &mb;
}
