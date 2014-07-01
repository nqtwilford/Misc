//constructor isn't called if new failed
#include <iostream>
using namespace std;

void my_new_handler()
{
	cout<<"new handler called"<<endl;
}

class NoMemory
{
public:
	NoMemory()
	{
		cout<<"NoMemory()"<<endl;
	}
	void *operator new(unsigned int sz) throw()
	{
		cout<<"operator new"<<endl;
		return 0;
//		return ::new char[sz];
	}
};

int main()
{
	set_new_handler(my_new_handler);	//new_handler will not be called automatically
	NoMemory *p = new NoMemory;
}
