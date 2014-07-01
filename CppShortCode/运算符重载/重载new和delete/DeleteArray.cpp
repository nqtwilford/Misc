#include <iostream>
using namespace std;

class Foo
{
public:
	static void *operator new [](size_t size)
	{
		cout<<"in new[]"<<endl;
		return ::operator new[](size);
	}
	static void operator delete [](void *p)
	{
		cout<<"in delete[]"<<endl;
		::operator delete[](p);
	}
};

int main()
{
	Foo *p1 = new Foo[3];
	cout<<p1<<endl;
	delete []p1;
	Foo *p2 = new Foo[3];
	cout<<p2<<endl;
	delete []p2;
}
