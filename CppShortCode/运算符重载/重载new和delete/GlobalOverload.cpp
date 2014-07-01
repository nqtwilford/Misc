#include <iostream>
#include <stdlib.h>
using namespace std;

void *operator new(size_t sz)
{
	cout<<"operator new:"<<sz<<" bytes"<<endl;
	void *m = malloc(sz);
	if(m == 0) cout<<"out of memory"<<endl;
	return m;
}

void operator delete(void *m)
{
	cout<<"operator delete"<<endl;
	free(m);
}

class C
{
public:
	C()
	{
		cout<<"C::C()"<<endl;
	}
	~C()
	{
		cout<<"C::~C()"<<endl;
	}
private:
	int i[100];
};

int main()
{
	cout<<"Creating and detroying an int"<<endl;
	int *pint = new int(23);
	delete pint;
	cout<<"Creating and destroying and C"<<endl;
	C *pc = new C;
	delete pc;
	cout<<"Creating and destroying and C[3]"<<endl;
	C *pc1 = new C[3];
	delete[] pc1;	//如果忘记加[]，可以看到只有一个对象被析构
	//吃尽内存
	long double *p;
	while(true)
		p = new long double[10000];
	return 0;
}
