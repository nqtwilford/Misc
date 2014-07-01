#include <iostream>
using namespace std;

class Base{};
class Derived : public Base
{
public:
	operator int(){return 1;}
};

void func(int){}
class Other{};

int main(int argc, char *argv[])
{
	int i = 0x7fff;
	long l;
	float f;
	//(1) typical castless conversions:
	l = i;
	f = i;
	//Also works:
	l = static_cast<long>(i);
	f = static_cast<float>(i);

	//(2) narrowing conversions:
//	i = f;	//cause warning
	i = static_cast<int>(f);

	//(3) forcing a conversion from void *:
	void *vp = &i;
	float *fp = (float *)vp;
	//new way
	fp = static_cast<float *>(vp);
	return 0;

	//(4) implicit type conversins, 
	//performed by the compiler:
	Derived d;
	Base *bp = &d;
	bp = static_cast<Base *>(&d);
	int x = d;
	x = static_cast<int>(d);
	func(d);
	func(static_cast<int>(d));

	//(5) static navigation of class hierarchies
	Derived *dp = static_cast<Derived *>(bp);
	//dynamic_cast is always safer.
	//However: the follow gives error message
//	Other *op = static_cast<Other *>(bp);
	//but the follow is legal
	Other *op2 = (Other *)bp;
	//So static_cast is safer than force conversion
}
