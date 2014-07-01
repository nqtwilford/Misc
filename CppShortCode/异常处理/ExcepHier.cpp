#include <iostream>
using namespace std;

class Trouble
{
public:
	virtual void print()
	{
		cout<<"I'm Trouble"<<endl;
	}
};
class Small : public Trouble
{
};
class Big : public Trouble
{
public:
	virtual void print()
	{
		cout<<"I'm Big"<<endl;
	}
};
void f()
{
	throw Big();
}

int main()
{
	try
	{
		f();
	}
	catch (Trouble &ex)
	{
		cout<<"caught trouble"<<endl;
		ex.print();
	}
	catch (Small &)
	{
		cout<<"caught small trouble"<<endl;
	}
	catch (Big &)
	{
		cout<<"caught big trouble"<<endl;
	}
}
