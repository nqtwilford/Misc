#include <iostream>
using namespace std;

template<int id>
class One
{
public:
	One()
	{
		cout<<typeid(*this).name()<<" constructor"<<endl;
	}
	~One()
	{
		cout<<typeid(*this).name()<<" destructor"<<endl;
	}
};

class Two: public One<0>
{
public:
	Two(){cout<<"Two::Two()"<<endl;}
	~Two(){cout<<"Two::~Two()"<<endl;}
private:
	One<1> m1;
	One<2> m2;
};

int main()
{
	Two o;
}
