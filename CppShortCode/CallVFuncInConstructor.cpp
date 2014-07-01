#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		f();	//this will call Base::f() or the Derived::f()
	}
	virtual void f()
	{
		cout<<"Base::f()"<<endl;
		g();
	}
	virtual void g()
	{
		cout<<"Base::g()"<<endl;
	}
};

class Derived: public Base
{
public:
	virtual void f()
	{
		cout<<"Derived::f()"<<endl;
		g();
	}
	virtual void g()
	{
		cout<<"Derived::g()"<<endl;
	}
};

int main()
{
	Derived d;	//Base::f()���ᱻ���ã���Ϊ�ڻ��๹���ʱ����������δ����
				//�������Derived::f()�������·���δ��ʼ���ĳ�Ա
				//ͬ�������������У�Ҳֻ�б��ذ汾���������ã���Ϊ�������Ѿ�����
				//������������ຯ����ͬ������ɷǷ�����
	system("pause");
	return 0;
}
