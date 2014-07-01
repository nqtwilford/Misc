//如果虚基类的构造函数带参数，
//在整个继承层次中的每一个子类
//都必须显示的调用虚基类的构造函数
//在下面的例子中，如果MI不显示调用Base的构造函数
//那么编译器将无法决定是将Base初始化为1还是2
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
