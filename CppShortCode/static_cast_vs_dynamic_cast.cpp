/* 向下类型转换时，应当使用dynamic_cast而不是static_cast */
#include <iostream>
using namespace std;

class A
{
public:
	virtual ~A(){}
};

class B : public A
{
public:
	virtual ~B(){}
};

class C : public A
{
public:
	virtual ~C(){}
	int m_i;
};

int main(int /*argc*/, char ** /*argv*/)
{
	A *pA = new B;
	cout<<static_cast<C *>(pA)<<endl;		//转换成功但是错误的指针
	cout<<dynamic_cast<C *>(pA)<<endl;	//转换失败得到空指针
	return EXIT_SUCCESS;
}
