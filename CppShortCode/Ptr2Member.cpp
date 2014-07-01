#include <iostream>
using namespace std;

class C
{
public:
	int i,j,k;
	void f()
	{
		cout<<i<<' '<<j<<' '<<k<<'\n';
	}
};

int main()
{
	C c;
	c.i = 1;
	c.j = 2;
	c.k = 3;
	C *pc = &c;

	int C::*pm = &C::j;
	cout<<c.*pm<<pc->*pm<<'\n';

	void (C::*pmf)() = &C::f;
	(c.*pmf)();
	(pc->*pmf)();
	return 0;
}
