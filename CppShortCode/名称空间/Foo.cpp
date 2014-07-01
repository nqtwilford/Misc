#include "Foo.h"
#include <iostream>
using namespace std;

//这个函数可以在另外的cpp中使用，只需要重新声明
//如果在其他cpp中定义了这个函数，将在连接时引起重定义
void print1()
{
	cout<<"A function you can access"<<endl;
}

namespace
{
	//这个函数处于匿名名称空间中，在其他cpp中无法访问
	//不会污染其他cpp的命名环境
	void print()
	{
		cout<<"A function you can not access"<<endl;
	}
}
namespace wilford
{
	//与print1类似
	void print2()
	{
		cout<<"A function you also can access"<<endl;
	}
	void Foo::f()
	{
		print();
	}
}
