#pragma warning ( disable: 4290 )
#include <iostream>
using namespace std;

class Up
{
};

class Fit
{
public:
	Fit() throw(float)
	{
		//cout<<"exception ocurred when construct Fit, throw a double"<<endl;
		throw Up();	//构造异常对象时又发生了新的异常
	} 
};

void g() throw(int)
{
	//cout<<"in g() throw a int"<<endl;
	throw 47;
}

void f(int i) throw(Up, Fit)
{
	switch(i)
	{
	case 1:
		//cout<<"throw a Up"<<endl;
		throw Up();
	case 2:
		//cout<<"throw a Fit"<<endl;
		throw Fit();
	default:
		//cout<<"call g()"<<endl;
		try{
			g();
		}
		catch(...)
		{
			//cout<<"An unknown exception caught, rethrow"<<endl;
			throw;
		}
	}
}


void my_unexpected()
{
	//cout<<"unexpected exception thrown, throw a Up"<<endl;
//	exit(1);
	throw Up();
}

void terminator()
{
	//cout<<"I'll be back!"<<endl;
	abort();
}

int main()
{
	set_unexpected(my_unexpected);
	set_terminate(terminator);
	for(int i = 1; i <= 3; ++i)
	{
		//cout<<"when "<<i<<" ----------------"<<endl;
		try
		{
			f(i);
		}
		catch (Up)
		{
			cout<<"Up caught"<<endl;
		}
		catch(Fit)
		{
			cout<<"Fit caught"<<endl;
		}
	}
}
