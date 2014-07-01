#include <iostream>

class Another
{
};

class Base
{
public:
	virtual void func() = 0;
};

class Derived : public Base
{
public:
	virtual void func(){}
};

void testfunc(){}

int main()
{
	std::cout<<typeid(Base).name()<<std::endl;
	std::cout<<typeid(Derived).name()<<std::endl;

	std::cout<<typeid(Base).before(typeid(Another))<<std::endl;
	std::cout<<typeid(Another).before(typeid(Derived))<<std::endl;

	std::cout<<typeid(Another).raw_name()<<std::endl;
	std::cout<<typeid(Base).raw_name()<<std::endl;
	std::cout<<typeid(testfunc).raw_name()<<std::endl;
	std::cout<<typeid(&Derived::func).raw_name()<<std::endl;

	return 0;
}
