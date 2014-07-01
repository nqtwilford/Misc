#include <iostream>

using namespace std;

class TestClass
{
public:
	TestClass()
	{
		cout<<"TestClass()"<<endl;
	}
	TestClass(TestClass &&other)
	{
		cout<<"TestClass(TestClass &&other)"<<endl;
	}
	~TestClass()
	{
		cout<<"~TestClass()"<<endl;
	}

};

TestClass getobj()
{
	TestClass obj;
	return obj;
}

int main()
{
	{
		const TestClass &obj = getobj();
		cout<<"-----------------"<<endl;
	}
	cout<<"----------------------"<<endl;
	{
		TestClass obj = getobj();
		cout<<"-----------------"<<endl;
	}
	cout<<"----------------------"<<endl;
	{
		getobj();
		cout<<"-----------------"<<endl;
	}
	return 0;
}
