#include <memory>
#include <iostream>
#include "my_shared_ptr.h"

using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout<<"Base::~Base()"<<endl;
	}
	virtual void func()
	{
		cout<<"Base::func()"<<endl;
	}
};

class Derived : public Base
{
public:
	virtual ~Derived()
	{
		cout<<"Derived::~Derived()"<<endl;
	}
	virtual void func()
	{
		cout<<"Derived::func()"<<endl;
	}
};

void CallWithBase(shared_ptr<Base> ptr)
{
	ptr->func();
}

void CallWithDerived(shared_ptr<Derived> ptr)
{
	ptr->func();
}

int main()
{
	{
		shared_ptr<Derived> ptr(new Derived);
		CallWithBase(ptr);	//auto up-cast
		shared_ptr<Base> ptr1 = ptr;
		//manually down-cast
		CallWithDerived(static_pointer_cast<Derived>(ptr1));
	}
	cout<<"test mine-------"<<endl;
	{
		//my_shared_ptr<Derived> ptr2(new Derived);
		//my_shared_ptr<Base> ptr3(ptr2);
	}

	return 0;
}
