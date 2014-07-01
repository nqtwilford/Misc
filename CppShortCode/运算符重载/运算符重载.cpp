#include <iostream>
using namespace std;

class Int
{
public:
	Int(int i)
	{
		m_i = i;
	}
	~Int()
	{
		
	}
	friend Int &operator++(Int &i);
	friend const Int operator++(Int &i, int);
	friend Int &operator--(Int &i);
	friend const Int operator--(Int &i, int);
	friend ostream &operator<<(ostream &os, const Int &i);
private:
	int m_i;
};

Int &operator++(Int &i)
{
	i.m_i++;
	return i;
}

const Int operator++(Int &i, int)
{
	Int temp = i;
	i.m_i++;
	return temp;
}

Int &operator--(Int &i)
{
	i.m_i--;
	return i;
}

const Int operator--(Int &i, int)
{
	Int temp = i;
	i.m_i--;
	return temp;
}

ostream &operator<<(ostream &os, const Int &i)
{
	os<<i.m_i;
	return os;
}

int main(void)
{
	Int i(3);
	cout<<i++<<i<<endl;
	cout<<i++<<i<<endl;
	cout<<i<<endl;
	return 0;
}
