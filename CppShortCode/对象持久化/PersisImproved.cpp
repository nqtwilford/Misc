//运用模版技术，即使在多重继承中，Persistent仍然正常工作
//但是模版化的Persistent失去了多态性
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

	void Print() const
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
};

int main()
{
	{
		ofstream ofs("Persis1.dat");
		Wdata obj(4, 2, 3);
		obj.Print();
		obj.Write(ofs);
	}
	{
		ifstream ifs("Persis1.dat");
		Wdata obj;
		obj.Read(ifs);
		obj.Print();
	}
}
