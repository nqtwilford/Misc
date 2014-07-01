#include <iostream>
using namespace std;

class C1
{
public:
	int f(int)
	{
		cout<<"C1:f(int)"<<endl;
	}
	int f(char)
	{
		cout<<"C1:f(char)"<<endl;
	}
	int f(float)
	{
		cout<<"C1:f(float)"<<endl;
	}
};

class C3
{
public:
	int f(int)
	{
		cout<<"C3:f(int)"<<endl;
	}
	int f(char)
	{
		cout<<"C3:f(char)"<<endl;
	}
	int f(float)
	{
		cout<<"C3:f(float)"<<endl;
	}
};

class C2: public C1, public C3
{
//public:
//	class C3{};
//	void f(C3 c)
//	{
//		C1::f(1);
//	}
};

int main()
{
	C2 obj;
	obj.C1::f(1.0f);
////	obj.f(1);		//为什么需要这种隐藏机制？
////	obj.f(2.0);		//参见Thinking in C++ 第13章
////	obj.f('d');
//	obj.f(C2::C3());
}
