#include <iostream>
using namespace std;

class Base
{
public:
	void foo()
	{
		cout<<"foo()"<<endl;
	}
};

class Drived : protected Base
{
public:
	using Base::foo;
};

int main(int argc, char **argv)
{
	Drived obj;
	obj.foo();
	return EXIT_SUCCESS;
}
