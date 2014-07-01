#include <iostream>
#include <iomanip>
using namespace std;

ostream &bywil(ostream &os)
{
	return os<<"  ----by wilford";
}

class mysetw
{
public:
	mysetw(int w)
	{
		m_w = w;
	}
	friend ostream &operator <<(ostream &os, const mysetw &mys)
	{
		os<<setw(mys.m_w);
		return os;
	}
private:
	int m_w;
};

int main()
{
	cout<<"Hello World!"<<bywil<<endl;
	cout<<setfill('_')<<mysetw(7)<<3.414<<endl;
	return 0;
}
