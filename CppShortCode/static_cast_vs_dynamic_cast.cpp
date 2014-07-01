/* ��������ת��ʱ��Ӧ��ʹ��dynamic_cast������static_cast */
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
	cout<<static_cast<C *>(pA)<<endl;		//ת���ɹ����Ǵ����ָ��
	cout<<dynamic_cast<C *>(pA)<<endl;	//ת��ʧ�ܵõ���ָ��
	return EXIT_SUCCESS;
}
