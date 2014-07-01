//这个例子虽然运行正确，但是虚函数表的地址不是每次都一样，
//将虚函数表地址一起持久化是不可靠的
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Persistent
{
public:
	void Write(ostream &os) const
	{
		T *p = (T *)this;
		int size = sizeof(T);
		os.write((char *)p, size);
	}
	void Read(istream &is)
	{
		T *p = (T *)this;
		int size = sizeof(T);
		is.read((char *)p, size);
	}
};

class Data
{
public:
	Data(int i1 = 0, int i2 = 0, int i3 = 0):
	m_i1(i1), m_i2(i2), m_i3(i3) {}

	virtual void Print() const
	{
		cout<<m_i1<<" "<<m_i2<<" "<<m_i3<<endl;
	}
private:
	int m_i1, m_i2, m_i3;
};

class Wdata: public Data, public Persistent<Wdata>
{
public:
	Wdata(int i1 = 0, int i2 = 0, int i3 = 0):
	Data(i1, i2, i3){}
	virtual void Print() const
	{
		cout<<"Call Data::Print() fron Wdata::Print"<<endl;
		Data::Print();
	}
};

int main()
{
	{
		ofstream ofs("Persis1.dat");
		Wdata obj(4, 2, 3);
		Data *pd = &obj;
		pd->Print();
		Persistent<Wdata> *pp = &obj;
		pp->Write(ofs);
	}
	{
		ifstream ifs("Persis1.dat");
		Wdata obj;
		Persistent<Wdata> *pp = &obj;
		pp->Read(ifs);
		Data *pd = &obj;
		pd->Print();
	}
}
