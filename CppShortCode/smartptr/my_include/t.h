#include <iostream>

class Base
{
public:
	Base(int i) : _i(i){}

	~Base()
	{
		std::cout<<"~Base() i:"<<_i<<std::endl;
	}

	virtual void func()
	{
		std::cout<<"Base::func() i:"<<_i<<std::endl;
	}

protected:
	int _i;
};

class Derived : public Base
{
public:
	Derived(int i): Base(i){}
	virtual void func() override
	{
		std::cout<<"Derived::func() i:"<<_i<<std::endl;
	}
};
