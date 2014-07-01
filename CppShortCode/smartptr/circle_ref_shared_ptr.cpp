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
	//b指针析构时，将b对象引用计数减1
	//a指针析构时，将a对象引用计数减1
	//实际此时a的另一个引用在完全由自己管理的b对象中
	//a和b都得不到释放
	shared_ptr<A> a(new A);
	shared_ptr<B> b(new B);
	a->b = b;
	b->a = a;
	return 0;
}
