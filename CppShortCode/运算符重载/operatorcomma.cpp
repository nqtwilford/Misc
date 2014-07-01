#include <iostream>
using namespace std;

class Class
{
public:
	Class &operator,(int)
	{
		cout<<"Class &operator,(int)"<<'\n';
		return *this;
	}
	Class &operator,(Class &)
	{
		cout<<"Class &operator,(Class &)"<<'\n';
		return *this;
	}
};

Class &operator,(int, Class &o)
{
	cout<<"Class &operator,(int, Class &o)"<<'\n';
	return o;
}

int main()
{
	Class o1, o2;
	1,o1,1,o2;
}
