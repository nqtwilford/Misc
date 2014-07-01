#include <memory>
#include <iostream>
using namespace std;

class A;
class B;

class A
{
public:
	~A()
	{
		cout<<"~A()"<<endl;
	}

	shared_ptr<B> b;
};

class B
{
public:
	~B()
	{
		cout<<"~B()"<<endl;
	}

	shared_ptr<A> a;
};

int main()
{
	//bָ������ʱ����b�������ü�����1
	//aָ������ʱ����a�������ü�����1
	//ʵ�ʴ�ʱa����һ����������ȫ���Լ������b������
	//a��b���ò����ͷ�
	shared_ptr<A> a(new A);
	shared_ptr<B> b(new B);
	a->b = b;
	b->a = a;
	return 0;
}
