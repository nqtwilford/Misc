#include <iostream>
using namespace std;

class MyInt
{
public:
	MyInt(int i):m_i(i){}
	MyInt &operator<<(int i)
	{
		m_i += i;
		return *this;
	}
	MyInt &operator>>(int i)
	{
		m_i -= i;
		return *this;
	}
	MyInt &operator<<(MyInt &(&manip)(MyInt &))
	{
		return manip(*this);
	}
	friend ostream &operator<<(ostream &os, const MyInt &mi)
	{
		return os<<mi.m_i;
	}
private:
	int m_i;
};

MyInt &addten(MyInt &mi)
{
	return mi<<10;
}

class add
{
public:
	add(int i)
	{
		m_i = i;
	}
	friend MyInt &operator<<(MyInt &mi, const add &ad)
	{
		return mi<<ad.m_i;
	}
private:
	int m_i;
};

int main()
{
	MyInt mi(1);
	mi<<2<<3>>1<<add(3)<<addten;
	cout<<mi<<endl;
	return 0;
}
