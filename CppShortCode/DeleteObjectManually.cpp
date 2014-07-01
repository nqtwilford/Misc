#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(): i(5)
	{
		cout<<"Constructing CTest"<<endl;
	}
	~CTest()
	{
		cout<<"Destructing CTest"<<endl;
	}
	int Geti(){return i;}
private:
	int i;
};

int main()
{
	//Can not manually delete object in stack
	CTest obj1;
	cout<<&obj1<<endl;
	CTest obj2;
	delete &obj2;
	cout<<&obj2<<endl;
	CTest obj3;
	cout<<&obj3<<endl;
	system("pause");
}
