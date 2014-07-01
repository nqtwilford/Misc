//�̳���ʹ�õ�virtual�ؼ������麯���������Ƶ�ԭ��
//��ʹ��ָ����ָ������Ӷ���
//��������MI�п��Ա�ֻ֤��һ�������Ӷ���
#include <iostream>
using namespace std;

class Base
{
public:
	virtual char *vf() const =0;
};
char *Base::vf() const
{
	return "Base";
}

class Derived1: virtual public Base
{
public:
	virtual char *vf() const
	{
		return "Derived1";
	}
};

class Derived2: virtual public Base
{
public:
	virtual char *vf() const
	{
		return "Derived2";
	}
};

class MI: public Derived1, public Derived2
{
public:
	virtual char *vf() const
	{
		return "MI";
//		return Derived2::Base::vf();
	}
};

int main()
{
	MI obj;
//	Base &refBase = obj; 
	Derived2 &refDerived2 = obj;
	Base &refBase = refDerived2;
	cout<<refBase.vf()<<endl;
}
