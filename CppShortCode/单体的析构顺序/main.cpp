#include "Singleton.h"
#include <fstream>
#include <iostream>
using namespace std;
ofstream out("out.txt");

class C1: public Singleton<C1>
{
private:
	C1()
	{
		out<<"C1 constructed"<<endl;
	}
	~C1();
	friend class Singleton<C1>;
public:
	void f()
	{
		out<<"C1::f()"<<endl;
	}
	
};

class C2: public Singleton<C2>
{
private:
	C2()
	{
		out<<"C2 constructed"<<endl;
	}
	~C2();
	friend class Singleton<C2>;
public:
	void f()
	{
		out<<"C2::f()"<<endl;
	}
	
};

C1::~C1()
{	//可能会出错，此时cout可能已经析构
	out<<"C1 destructed"<<endl;
	out<<"Call C2"<<endl;
	C2::Instance().f();
}

C2::~C2()
{
	out<<"C2 destructed"<<endl;
	out<<"Call C1"<<endl;
	C1::Instance().f();
}

class CTest
{
public:
	void f()
	{
		C1::Instance();
		C2::Instance();
	}
};

int main()
{
	out<<"start main"<<endl;
	CTest obj;
	obj.f();
	system("pause");
	out<<"end main"<<endl;
	return 0;
}
