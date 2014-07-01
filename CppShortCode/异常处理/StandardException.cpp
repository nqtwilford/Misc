#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception
{
public:
	virtual const char *what() const throw()
	{
		return "Test exception";
	}
};

void f()
{
	throw MyException();
}

int main()
{
	try
	{
		f();
	}
	catch (exception &ex)
	{
		cout<<ex.what()<<endl;
	}
}
