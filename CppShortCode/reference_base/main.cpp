#include <iostream>

using namespace std;

class Base
{
public:
	int x, y;
};

class Derived : public Base
{
public:
	Derived()
		: u(x)
		, v(y)
	{}
	int &u, &v;
};

int main()
{
	Derived obj;
	obj.x = 10;
	obj.y = 12;
	cout<<obj.u<<" "<<obj.v<<endl;
	cout<<sizeof(Base)<<" "<<sizeof(Derived)<<endl;
	return 0;
}
