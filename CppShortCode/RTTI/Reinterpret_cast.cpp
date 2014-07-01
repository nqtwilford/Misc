#include <iostream>
using namespace std;

class Base
{
public:
	virtual void f(){cout<<"virtual func called"<<endl;}
};
class X : public Base
{
public:
	X(){memset(a, 0, sz * sizeof(int));}
	int membsize(){return sizeof(a);}
	friend ostream &operator<<(ostream &os, const X &x)
	{
		for(int i = 0; i < sz; ++i)
		{
			os<<x.a[i]<<' ';
		}
		return os;
	}
private:
	static const int sz = 5;
	int a[sz];
};

int main(int argc, char *argv[])
{
	X x;
	Base *pb = &x;
	cout<<x<<endl;
	pb->f();
	int *xp = reinterpret_cast<int *>(&x);
	xp[0] = 47;	//exactly the VPTR is modified
	cout<<x<<endl;
//	pb->f();	//can the virtual func still be called? No!

	//jump over the vptr
	X x2;
	const int vptr_size = sizeof(X) - x2.membsize();
	long l = reinterpret_cast<long>(&x2);
	l += vptr_size;
	xp = reinterpret_cast<int *>(l);
	xp[0] = 47;
	cout<<x2<<endl;
	return 0;
}
