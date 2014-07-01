//new with specific location
#include <iostream>
using namespace std;

class C
{
public:
	C(int i = 0): m_i(i){}
	~C()
	{
		cout<<"C::~C()"<<endl;
	}
	void *operator new(size_t, void *loc)
	{
		cout<<"operator new"<<endl;
		return loc;
	}
private:
	int m_i;
};

int main()
{
//	C *p1 = new C;	//illegal
	int l[10];
	C *p = new(l) C(47);
	cout<<l<<" "<<p<<endl;	//same location
	cout<<l[0]<<endl;	//47
//	p->~C();	//explicit call destructor
}
