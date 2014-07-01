/*模板类中的静态对象如果没有使用，不会被创建
**非模板类中的静态对象即使没有被使用，也会创建，
**并且会首先创建
*/
#include <iostream>
#include <fstream>
using namespace std;
ofstream out("Test.txt");

class C0
{
public:
	C0()
	{
		out<<"C0 constructed"<<endl;
	}
	~C0()
	{
		out<<"C0 destructed"<<endl;
	}
};

template <class T>
class C1
{
public:
	static T &f()
	{
		return obj1;
	}
	static C0 &g()
	{
		return obj2;
	}
private:
	static T obj1;		
	static C0 obj2;
};
template <class T>
T C1<T>::obj1;
template <class T>
C0 C1<T>::obj2;

class C3
{
public:
	C3()
	{
		out<<"C3 constructed"<<endl;
	}
	~C3()
	{
		out<<"C3 destructed"<<endl;
	}
};

class C2: public C1<C2>
{
private:
	C2()
	{
		out<<"C2 constructed"<<endl;
	}
	~C2()
	{
		out<<"C2 destructed"<<endl;
	}
	friend class C1<C2>;
	static C3 obj3;
};
C3 C2::obj3;

int main()
{
	out<<"start main"<<endl;
	C2::f();
	C2::g();
//	C1<int> c;
	system("pause");
	out<<"end main"<<endl;
	return 0;
}
