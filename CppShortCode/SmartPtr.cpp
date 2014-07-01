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
	//�������캯��
	SmartPtr(const SmartPtr &obj)
		:m_p(obj.m_p)
	{
		incr_use();
	}
	//��ֵ������
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
	//��������
	~SmartPtr()
	{
		decr_use();
	}
	//boolת��������
	operator bool()
	{
		return m_p;
	}
	//->������
	T *operator ->()
	{
		return m_p;
	}
	//*������
	T &operator *()
	{
		return *m_p;
	}
	//ȡ�ü������ĸ���
	static size_t GetCounterNum()
	{
		return m_counter.size();
	}
	//��ʾ��ָ�뵱ǰ����
	static void WriteCounts()
	{
		for(tyCounter::iterator iter = m_counter.begin();
			iter != m_counter.end(); ++iter)
		{
			cout<<(iter->first)<<"\t"<<(iter->second)<<endl;
		}
	}
private:
	//���Ӽ���
	void incr_use()
	{
		if(m_p != 0)
		{
			++m_counter[m_p];
		}
	}
	//���ټ���
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
