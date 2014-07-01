#include <memory>
#include "my_include/t.h"

using namespace std;

//can be used as return value
unique_ptr<Base> NewBase()
{
	unique_ptr<Base> t(new Base(10));
	return t;
}

int main()
{
	unique_ptr<Base> ptr(new Base(5));
	//unique_ptr<Base> ptr1 = ptr;	//compile error
	unique_ptr<Base> ptr2 = move(ptr);	//legal
	cout<<ptr.get()<<endl;	//00000000
	//Base *t = NewBase();	//illegal
	unique_ptr<Base> ptr3 = NewBase();
	return 0;
}
