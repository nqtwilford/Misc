#include <iostream>
using namespace std;

class FunctionObject
{
public:
	void operator()()
	{
		cout<<"I'm called with nothing"<<'\n';
	}
	int operator()(int i)
	{
		cout<<"I'm called with integer: "<<i<<'\n';
		return i;
	}
	void operator()(const char *str)
	{
		cout<<"I'm called with string: "<<str<<'\n';
	}
};

int main()
{
	FunctionObject func;
	func();
	cout<<func(5)<<'\n';
	func("Hello World!");
	return 0;
}
