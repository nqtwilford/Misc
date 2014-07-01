#include <iostream>
using namespace std;

class NonDerivableHelper   
{   
private:
	NonDerivableHelper()
	{
		cout<<"NonDerivableHelper()"<<endl;
	}   
	friend class NonDerivable;
//	friend class SomeClass;
};   
//virtual很关键，什么是虚继承呢
class NonDerivable: public virtual NonDerivableHelper
{   
public:
	NonDerivable()
	{
		cout<<"NonDerivable()"<<endl;
	}
};   
    
class SomeClass : public NonDerivable
{   
public:
	SomeClass()
	{
		cout<<"SomeClass()"<<endl;
	}
};   
    
int main()
{   
//	NonDerivable obj;		//可实例化
	SomeClass obj1;		//不可实例化
	return   0;   
}
