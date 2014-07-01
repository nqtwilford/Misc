//Persistent class works fine with single inheritance
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

class Data: public Persistent
{
public:
	Data(int i1 = 0, int i2 = 0, int i3 = 0):
	Persistent(sizeof(Data)),
	m_i1(i1), m_i2(i2), m_i3(i3) {}

	void Print() const
	{
		cout<<m_i1<<" "<<m_i2<<" "<<m_i3<<endl;
	}
private:
	int m_i1, m_i2, m_i3;
};

int main()
{
	{
		ofstream ofs("Persis1.dat");
		Data obj(1, 2, 3);
		obj.Print();
		obj.Write(ofs);
	}
	{
		ifstream ifs("Persis1.dat");
		Data obj;
		obj.Print();
		obj.Read(ifs);
		obj.Print();
	}
}
