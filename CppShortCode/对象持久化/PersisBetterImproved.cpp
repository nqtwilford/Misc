//在模版类的上层在加一个抽象层，多态性得以保留
#include <iostream>
#include <fstream>
using namespace std;

class Persistent
{
public:
	virtual void Write(ostream &os) const = 0;
	virtual void Read(istream &is) = 0;
};

template <class T>
class PersistentHelper: public Persistent
{
public:
	virtual void Write(ostream &os) const
	{
		T *p = (T *)this;
		int size = sizeof(T);
		os.write((char *)p, size);
	}
	virtual void Read(istream &is)
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

	void Print() const
	{
		cout<<m_i1<<" "<<m_i2<<" "<<m_i3<<endl;
	}
protected:
	int m_i1, m_i2, m_i3;
};

class Wdata1: public Data, public PersistentHelper<Wdata1>
{
public:
	Wdata1(int i1 = 0, int i2 = 0, int i3 = 0):
	Data(i1, i2, i3){}
};

class Wdata2: public Data, public PersistentHelper<Wdata2>
{
public:
	Wdata2(int i1 = 0, int i2 = 0, int i3 = 0):
	Data(i1, i2, i3){}
	virtual void Write(ostream &os) const
	{
		os<<m_i1<<" "<<m_i2<<" "<<m_i3;
	}
	virtual void Read(istream &is)
	{
		is>>m_i1>>m_i2>>m_i3;
	}
};

int main()
{
	{
		ofstream ofs1("Persis1.dat"), ofs2("Persis2.dat");
		Wdata1 obj1(1, 2, 3);
		Wdata2 obj2(4, 5, 6);
		obj1.Print();
		obj2.Print();
		Persistent *p1 = &obj1;
		p1->Write(ofs1);
		Persistent *p2 = &obj2;
		p2->Write(ofs2);
	}
	{
		ifstream ifs1("Persis1.dat"), ifs2("Persis2.dat");
		Wdata1 obj1;
		Wdata2 obj2;
		Persistent *p1 = &obj1;
		p1->Read(ifs1);
		Persistent *p2 = &obj2;
		p2->Read(ifs2);
		obj1.Print();
		obj2.Print();
	}
}
