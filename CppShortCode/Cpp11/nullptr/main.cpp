#include <iostream>

class Foo
{
public:
	Foo(std::nullptr_t)
	{
		std::cout<<"correct"<<std::endl;
	}
	Foo(int *)
	{
		std::cout<<"error"<<std::endl;
	}
};

int main()
{
	Foo obj(0);
}
