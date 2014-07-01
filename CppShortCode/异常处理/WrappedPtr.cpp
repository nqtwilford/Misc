#include <iostream>
using namespace std;

ostream &out = cout;

template<class T, int SIZE = 1>
class PWrap
{
public:
	class RangeError{};
	PWrap()
	{
		ptr = new T[SIZE];
		out<<"PWrap constructor"<<endl;
	}
	~PWrap()
	{
		delete []ptr;
		out<<"PWrap destructor"<<endl;
	}
	T &operator[](int i) throw(RangeError)
	{
		if(i >= 0 && i < SIZE)
			return ptr[i];
		throw RangeError();
	}
private:
	T *ptr;
};

class Bonk
{
public:
	Bonk(){out<<"Bonk()"<<endl;}
	~Bonk(){out<<"~Bonk()"<<endl;}
	void g(){}
};

class OG
{
public:
	void *operator new[](size_t sz)
	{
		out<<"allocating an og"<<endl;
		throw int(47);
		return 0;
	}
	void operator delete[](void *p)
	{
		out<<"deallocating an og"<<endl;
		::delete (char *)p;	//是否真的释放了所有空间呢
	}
};

class UseResources
{
public:
	UseResources() : bp(), op()
	{
		out<<"UseResource()"<<endl;
	}
	~UseResources()
	{
		out<<"~UseResource()"<<endl;
	}
	void f()
	{
		bp[1].g();
	}
private:
	PWrap<Bonk, 3> bp;
	PWrap<OG> op;
};

int main()
{
	try
	{
		UseResources ur;
	}
	catch (int)
	{
		out<<"inside handler"<<endl;
	}
	catch(...)
	{
		out<<"inside catch(...)"<<endl;
	}
}
