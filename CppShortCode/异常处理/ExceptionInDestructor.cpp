#include <iostream>
using namespace std;

void terminator()
{
	cout<<"I'll be back!"<<endl;
	abort();
}

class Botch
{
public:
	class Fruit
	{
	};

	void f()
	{
		cout<<"Botch::f()"<<endl;
		throw Fruit();
	}
	//�����������׳��쳣����Ҳ���ܱ�����
	~Botch()
	{ 
		cout<<"Botch::~Botch()"<<endl;
		throw 'c'; 
	}	
};

int main()
{
	set_terminate(terminator);
	try
	{
		Botch b;
		b.f();
	}
	catch (...)
	{
		cout<<"Inside catch(...)"<<endl;
	}
}
