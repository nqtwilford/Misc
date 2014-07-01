#include "Foo.h"
#include <iostream>

using namespace wilford;
using namespace std;

void print()
{
	cout<<"print"<<endl;
}
void print1();
//{
//	cout<<"print1"<<endl;
//}
namespace wilford
{
	void print2();
//	{
//		cout<<"print2"<<endl;
//	}
}
int main()
{
	Foo obj;
	obj.f();
	print();
	print1();
	print2();
}
