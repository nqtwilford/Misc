//���캯���ĵ���˳��
//1�����๹�캯�� 
//2����Ա�����캯�����Զ���˳��Ϊ׼�����ʼ���б��е�˳���޹أ�
//3�������캯��
//4����������˳���빹�캯���෴
#include <iostream>
using namespace std;

#define CLASS(ID) \
class ID \
{\
public:\
	ID(int)\
	{\
		cout<<#ID" constructed"<<endl;\
	}\
	~ID()\
	{\
		cout<<#ID" destructed"<<endl;\
	}\
};\

CLASS(Base1)
CLASS(Member1)
CLASS(Member2)
CLASS(Member3)
CLASS(Member4)

class Derived1: public Base1
{
public:
	Derived1(int): m2(1), m1(2), Base1(1)
	{
		cout<<"Derived1 constructed"<<endl;
	}
	~Derived1()
	{
		cout<<"Derived1 destructed"<<endl;
	}
private:
	Member1 m1;
	Member2 m2;
};

class Derived2: public Derived1
{
public:
	Derived2(): m3(1), Derived1(2), m4(2)
	{
		cout<<"Derived2 constructed"<<endl;
	}
	~Derived2()
	{
		cout<<"Derived2 destructed"<<endl;
	}
private:
	Member3 m3;
	Member4 m4;
};

int main()
{
	Derived2 d2;
}
