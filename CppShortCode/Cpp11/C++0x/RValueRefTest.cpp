#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		cout<<"Test()"<<endl;
	}
	~Test()
	{
		cout<<"~Test()"<<endl;
	}
};

Test GetATest()
{
	return Test();
}

int main()
{
	Test obj = GetATest();
	
	//system("pause");
}