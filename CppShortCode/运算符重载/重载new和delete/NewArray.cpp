#include <iostream>
using namespace std;

class C
{
public:
	C()
	{
		cout<<"C constructor"<<endl;
	}
	~C()
	{
		cout<<"C destructor"<<endl;
	}
	void *operator new(size_t sz)
	{
		cout<<"new"<<endl;
		return ::new char[sz];
	}
	void *operator new[](size_t sz)
	{
		cout<<"new[]"<<endl;
		return ::new char[sz];
	}
	void operator delete(void *m)
	{
		cout<<"delete"<<endl;
		return ::delete[] (char *)m;
	}
	void operator delete[](void *m)
	{
		cout<<"delete[]"<<endl;
		return ::delete[] (char *)m;
	}
};

int main()
{
	C *p = new C;
	delete p;
	C *ps = new C[5];
	delete[] ps;
}
