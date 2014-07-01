#include <iostream>
using namespace std;

template <class T>
class C
{
public:
	void f(){}
};

template<>
class C<int>
{
public:
	void f()
	{
		cout<<"C<int>::f()"<<endl;
	}
};

int main()
{
	C<int> a;
	a.f();
}
