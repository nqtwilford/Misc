#include <iostream>
using namespace std;

class Exception2
{
public:
//	Exception2(Exception1 &){}
};

class Exception1
{
public:
	operator Exception2()
	{
		return Exception2();
	}
};



void f()
{
	throw Exception1();
}

int main()
{
	try
	{
		f();
	}
	catch(Exception2)
	{
		cout<<"inside catch(Exception2)"<<endl;
	}
	catch(Exception1)
	{
		cout<<"inside catch(Exception1)"<<endl;
	}
}
