#include <iostream>
#include <map>
#include <string>
using namespace std;

template <class T>
class SmartPtr
{
public:
	SmartPtr(T *p = 0)
		:m_p(p)
	{
		incr_use();
	}
	//拷贝构造函数
	SmartPtr(const SmartPtr &obj)
		:m_p(obj.m_p)
	{
		incr_use();
	}
	//赋值操作符
	SmartPtr &operator =(const SmartPtr &obj)
	{
		if(this != &obj)
		{
			decr_use();
			m_p = obj.m_p;
			incr_use();
		}
		return *this;
	}
	//析构函数
	~SmartPtr()
	{
		decr_use();
	}
	//bool转换操作符
	operator bool()
	{
		return m_p;
	}
	//->操作符
	T *operator ->()
	{
		return m_p;
	}
	//*操作符
	T &operator *()
	{
		return *m_p;
	}
	//取得计数器的个数
	static size_t GetCounterNum()
	{
		return m_counter.size();
	}
	//显示各指针当前计数
	static void WriteCounts()
	{
		for(tyCounter::iterator iter = m_counter.begin();
			iter != m_counter.end(); ++iter)
		{
			cout<<(iter->first)<<"\t"<<(iter->second)<<endl;
		}
	}
private:
	//增加计数
	void incr_use()
	{
		if(m_p != 0)
		{
			++m_counter[m_p];
		}
	}
	//减少计数
	void decr_use()
	{
		if(m_p != 0)
		{
			if(--m_counter[m_p] == 0)
			{
				m_counter.erase(m_p);
				delete m_p;
			}
		}
	}
private:
	typedef map<T *, size_t> tyCounter;
private:
	T *m_p;
	static tyCounter m_counter;
};

template <class T>
map<T *, size_t> SmartPtr<T>::m_counter;

class CTest
{
public:
	CTest(string name): m_name(name)
	{
		cout<<m_name<<" borned"<<endl;
	}
	~CTest()
	{
		cout<<m_name<<" dying"<<endl;
	}
	void SayHello()
	{
		cout<<"Hello everybody, I'm "<<m_name<<endl;
	}
private:
	string m_name;
};

void test1()
{
	SmartPtr<CTest> p, p2;
	{
		CTest *pCTest = new CTest("Object 1");
		SmartPtr<CTest> p1 = pCTest;
		p1 = p1;
		p1->SayHello();
		p = p1;
		SmartPtr<CTest> p2 = pCTest;
		p->SayHello();
		p1 = new CTest("Object 2");
		(*p1).SayHello();
	}
	cout<<"---------"<<endl;
}

class Base
{
public:
	virtual void foo()
	{
		cout<<"Base::foo()"<<endl;
	}
	virtual ~Base(){}
};

class Derived : public Base
{
public:
	virtual void foo()
	{
		cout<<"Derived::foo()"<<endl;
	}
	virtual ~Derived()
	{
		cout<<"Derived destructed"<<endl;
	}
};

void test2()
{
	SmartPtr<Base> p = new Derived();
	p->foo();
}

int main(int argc, char **argv)
{
	test2();
	return EXIT_SUCCESS;
}
