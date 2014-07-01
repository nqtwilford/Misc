#include <iostream>
#include <string>

class Base
{
public:
	Base(const std::string &name)
		: _name(name)
	{}

	void Show()
	{
		std::cout<<_name<<std::endl;
	}

private:
	std::string _name;
};

class Derived : public Base
{
public:
	using Base::Base;
};

int main()
{
	Derived obj("hello");
	obj.Show();
	return 0;
}
