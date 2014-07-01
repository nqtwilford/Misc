#include <iostream>
using namespace std;

class Base
{
public:
	~Base();
};
Base::~Base()
{
	cout<<"Base::~Base()"<<endl;
}

class Derived: public Base
{
public:
	~Derived()
	{
		cout<<"Derived::~Derived()"<<endl;
	}
};

class Derived2: public Derived
{
public:
	~Derived2()
	{
		cout<<"Derived2::~Derived2"<<endl;
	}
};

int main()
{
	//����������������麯�������ܲ�����ȷ��������������
	Base *p = new Derived2;
	delete p;
	Derived *p1 = new Derived2;
	delete p1;
}
