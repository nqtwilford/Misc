//��������Ĺ��캯����������
//�������̳в���е�ÿһ������
//��������ʾ�ĵ��������Ĺ��캯��
//������������У����MI����ʾ����Base�Ĺ��캯��
//��ô���������޷������ǽ�Base��ʼ��Ϊ1����2
#include <iostream>
using namespace std;

class Base
{
public:
	Base(int i): m_i(i){}
	int Geti(){return m_i;}
	virtual char *vf() const =0;
private:
	int m_i;
};
char *Base::vf() const
{
	return "Base";
}

class Derived1: virtual public Base
{
public:
	Derived1(): Base(1){}
	virtual char *vf() const
	{
		return "Derived1";
	}
};

class Derived2: virtual public Base
{
public:
	Derived2(): Base(2){}
	virtual char *vf() const
	{
		return "Derived2";
	}
};

class MI: public Derived1, public Derived2
{
public:
	MI(): Base(3){}
	virtual char *vf() const
	{
//		return "MI";
		return Derived1::Base::vf();
	}
};

int main()
{
	MI obj;
	Base &refBase = obj;
	cout<<refBase.Geti()<<endl;	//3,not 1 or 2
}
