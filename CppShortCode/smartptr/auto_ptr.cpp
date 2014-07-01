#include <memory>
#include "t.h"

using namespace std;

int main()
{
	auto_ptr<Base> ptr(new Base(5));
	auto_ptr<Base> ptr1 = ptr;
	cout<<ptr.get()<<" "<<ptr1.get()<<endl;	//null valid
	//ptr->func();	//crash
	ptr1->func();
	return 0;
}
