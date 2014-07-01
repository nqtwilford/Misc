#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout<<"A constructed"<<endl;
	}
	~A()
	{
		cout<<"A destructed"<<endl;
	}
};

class B
{
public:
	B()
	{
		cout<<"B constructed"<<endl;
	}
	~B()
	{
		cout<<"B destructed"<<endl;
	}
};

class C
{
public:
	C():m_b(),m_a()
	{
		cout<<"C constructed"<<endl;
	}
	~C()
	{
		cout<<"C destructed"<<endl;
	}
private:
	
	A m_a;
	B m_b;
};

int main()
{
	C c;
}
