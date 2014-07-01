#include <iostream>
using namespace std;

class Object
{
public:
	Object():m_i(0){};
	int operator[](const char *str) const
	{
		cout<<"const version:"<<str<<'\n';
		return m_i;
	}
	int &operator[](const char *str) 
	{
		cout<<"nonconst version:"<<str<<'\n';
		return m_i;
	}
private:
	int m_i;
};

int main()
{
	Object obj;
	obj["Hello"] = 3;
	cout<<obj["Hello"]<<'\n';
	const Object &objref = obj;
//	objref["Hello"] = 4;	//compile error
	cout<<objref["Hello"]<<endl;
}
