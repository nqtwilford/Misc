#include <iostream>
using namespace std;

class Base
{
public:
	virtual void dummy(){}
};

class Derived : public Base
{
};

class Extended : public Base
{
};

int main()
{
	Derived d;
	Base &b = d;
	cout<<typeid(&b).name()<<endl;	//Base * not Derived *

	try
	{
		//b refered to Derived not Extended, 
		//but a reference can not be null,
		//so throw exception
		Extended &e = dynamic_cast<Extended &>(b);	
	}
	catch (bad_cast &ex)
	{
		cout<<ex.what()<<endl;
	}

	Extended *pe = 0;
	try
	{
		typeid(*pe);
	}
	catch (bad_typeid &ex)
	{
		cout<<ex.what()<<endl;
	}

}
