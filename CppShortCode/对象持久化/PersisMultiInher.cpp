//类Wdata2的对象持久化无法正常工作，
//因为在父类Persistent中，this指针并不代表对象的起始指针
#include <iostream>
#include <fstream>
using namespace std;

class Persistent
{
public:
	Persistent(int size): m_iSize(size){}
	void Write(ostream &os) const
	{
		os.write((char *)this, m_iSize);
	}
	void Read(istream &is)
	{
		is.read((char *)this, m_iSize);
	}
private:
	int m_iSize;
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
private:
	int m_i1, m_i2, m_i3;
};

class Wdata1: public Persistent, public Data
{
public:
	Wdata1(int i1 = 0, int i2 = 0, int i3 = 0):
	Data(i1, i2, i3),
	Persistent(sizeof(Wdata1)){}
};

class Wdata2: public Data, public Persistent
{
public:
	Wdata2(int i1 = 0, int i2 = 0, int i3 = 0):
	Data(i1, i2, i3),
	Persistent(sizeof(Wdata2)){}
};

int main()
{
	{
		ofstream ofs1("Persis1.dat"), ofs2("Persis2.dat");
		Wdata1 obj1(1, 2, 3);
		Wdata2 obj2(4, 5, 6);
		obj1.Print();
		obj2.Print();
		obj1.Write(ofs1);
		obj2.Write(ofs2);
	}
	{
		ifstream ifs1("Persis1.dat"), ifs2("Persis2.dat");
		Wdata1 obj1;
		Wdata2 obj2;
		obj1.Read(ifs1);
		obj2.Read(ifs2);
		obj1.Print();
		obj2.Print();
	}
}
