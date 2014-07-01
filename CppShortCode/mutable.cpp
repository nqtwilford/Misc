#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class C
{
public:
	C(int i)
	{
		m_i = i;
	}
	void f() const
	{
		m_i++;
	}
	
	int Geti() const
	{
		return m_i;
	}
private:
	mutable int m_i;
};

int main()
{
	const C c(1);
	c.f();
	cout<<c.Geti();
	return 0;
}
