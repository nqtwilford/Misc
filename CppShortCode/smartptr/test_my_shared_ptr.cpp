#include "my_include/t.h"
#include "my_shared_ptr.h"

int main()
{
	{
	cout<<"---------------------"<<endl;
	my_shared_ptr<Base> p(new Base(5));
	my_shared_ptr<Base> p1(p);
	my_shared_ptr<Base> p2 = p1;
	}

	{
	cout<<"---------------------"<<endl;
	my_shared_ptr<Derived> pD(new Derived(5));
	(*pD).func();
	my_shared_ptr<Base> pB = pD;
	pB->func();
	my_shared_ptr<Derived> pD1 = dynamic_ptr_cast<Derived>(pB);
	pD1->func();
	}

	{
	cout<<"---------------------"<<endl;
	my_shared_ptr<Base> pB;
	if(!pB)
		cout<<"pB is nullptr"<<endl;
	//int i = pB;	//cannot
	BOOL_SUBST b = pB;	//虽然这样可以通过编译，但也造不成什么伤害了
	//cout<<i<<endl;
	}
}
