/*���û���麯�����ƣ�typeid�޷��ó���ȷ������*/
#include <iostream>
using namespace std;

class Base1
{
public:
	virtual void Foo(){}
};

class Base2
{
};

class Mid : virtual public Base1, virtual public Base2
{
};

class Derived : public Mid
{
};

int main()
{
	Derived *pd = new Derived;
	Base1 *pb1 = pd;
	Base2 *pb2 = pd;
	cout<<typeid(*pb1).name()<<endl;	//Derived
	cout<<typeid(*pb2).name()<<endl;	//Base2
}
