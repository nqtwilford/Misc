//函数f，g，h完全等价，数组的长度并不能通过参数传递到函数内部
//形参i自动退化为指针，为了避免误会，应只使用指针形式
//但可以使用引用形式传递数组如函数foo，然而函数foo只能接受10个元素的int数组
//利用模板，可以接受任意个数的数组，如函数bar。
//同样，利用模板，也可以接受任意类型的数组
#include <iostream>
#include <vector>
using namespace std;

void f(int i[10])
{
	cout<<sizeof(i)<<endl;
}

void g(int i[])
{
	cout<<sizeof(i)<<endl;
}

void h(int *i)
{
	cout<<sizeof(i)<<endl;
}

void foo(const int (&i)[10])
{
	cout<<sizeof(i)<<endl;
}

template<size_t N>
void bar(const int (&i)[N])
{
	cout<<sizeof(i)<<endl;
}

int main(int argc, char *argv[])
{
	int i[5] = {0};
	f(i);
	g(i);
	h(i);
//	foo(i);		//illegal
	int j[10] = {0};
	foo(j);
	int k[6] = {0};
//	foo(k);		//illegal
	bar(k);
	return 0;
}
