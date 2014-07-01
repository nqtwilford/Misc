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
//virtual�ܹؼ���ʲô����̳���
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
//	NonDerivable obj;		//��ʵ����
	SomeClass obj1;		//����ʵ����
	return   0;   
}
