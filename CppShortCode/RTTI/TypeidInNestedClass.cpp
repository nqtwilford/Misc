#include <iostream>
using namespace std;

class One
{
private:
	class Nested{};
public:
	One(){ n = new Nested;}
	~One(){delete n;}
	Nested *Getn() const {return n;}
	class //Anonymous nested class
	{
	} obj;
private:
	Nested *n;
};

int main()
{
	One o;
	cout<<typeid(*o.Getn()).name()<<endl;
	cout<<typeid(o.obj).name()<<endl;
}
