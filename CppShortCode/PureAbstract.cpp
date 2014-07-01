//���麯��Ҳ�����ж��壬������Ȼ����ʵ��������ֻ���ṩ������ʹ��
#include <iostream>
using namespace std;

class PureAbstract
{
public:
	virtual void f() = 0;
};

void PureAbstract::f()
{
	cout<<"PureAbstract::f()"<<endl;
}

class Concrete: public PureAbstract
{
public:
	virtual void f()
	{
		cout<<"Concrete::f()"<<endl;
		PureAbstract::f();
	}
};

int main()
{
//	PureAbstract obj1;
	Concrete obj;
	obj.f();
}
