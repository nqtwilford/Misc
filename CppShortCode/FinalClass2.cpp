#include <iostream>
using namespace std;

class NonDerivableHelper   
{   
protected:
	NonDerivableHelper()
	{
		cout<<"NonDerivableHelper()"<<endl;
	}   
};   
//virtual�ܹؼ���ʲô����̳���
class NonDerivable: private virtual NonDerivableHelper
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
	NonDerivable obj;		//��ʵ����
//	SomeClass obj1;		//����ʵ����
	return   0;   
}
