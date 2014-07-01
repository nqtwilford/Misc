#include <iostream>
using namespace std;

class Base
{
public:
	virtual void Foo(){}
};

class Mid1 : virtual public Base
{
};

class Mid2 : virtual public Base
{
};

class Derived : public Mid1, public Mid2
{
};

int main()
{
	Derived *pd = new Derived;
	Base *pb = pd;
//	Derived *pd1 = (Derived *)pb;	//not allowed, use dynamic_cast
	Derived *pd2 = dynamic_cast<Derived *>(pb);
}
