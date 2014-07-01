#include <iostream>
#include <exception>
#include <eh.h>
using namespace std;

void MyUnexpectdHandler()
{
	cout<<"In MyUnexpectdHandler"<<endl;
	throw 1.0f;
}

void func() throw(float)
{
	unexpected();
	throw 'e';
}

int main()
{
	set_unexpected(MyUnexpectdHandler);
	try
	{
		func();
	}
	catch (int)
	{
		cout<<"caught int"<<endl;
	}
	catch(...)
	{
		cout<<"caught other"<<endl;
	}
}
