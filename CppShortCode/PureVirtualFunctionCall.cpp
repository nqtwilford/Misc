//不要在析构函数中调用自己的成员函数，它可能间接调用了一个纯虚函数
//因为子类会在父类之前销毁，所以此时子类已经不存在，导致调用了父类的纯虚函数
#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(){}
	~Parent()
	{
//		ClearAll();
		ThePure();	//编译器可以检测出直接的调用，但不能检测出间接的调用
	}
	void ClearAll()
	{
		ThePure();
	}
	virtual bool ThePure() = 0;
};

class Child: public Parent
{
public:
	Child()
	{
	}
	~Child()
	{
	}
	virtual bool ThePure()
	{
		return true;
	}
};

int main(int argc, char **args)
{
	Child c;
}
