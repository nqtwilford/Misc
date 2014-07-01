#include <iostream>
using namespace std;

class String
{
public:
	String()	//无参数构造
	{
		cout<<"//无参数构造"<<endl;
		cout<<"//申请内存:1B"<<endl;
		m_data = new char[1];
		m_data[0] = '\0';
	}
	String(const char *str)		//带参数构造
	{
		cout<<"//带参数构造"<<endl;
		init(str);
	}
	String(const String &another)	//拷贝构造
	{
		cout<<"//拷贝构造"<<endl;
		init(another.m_data);
	}
	~String()
	{
		cout<<"//释放内存:"<<(strlen(m_data)+1)<<"B"<<endl;
		delete []m_data;
	}
	String &operator =(const String &another)	//赋值
	{
		cout<<"//赋值"<<endl;
		if(this == &another)	//检查自赋值，非常必要
			return *this;

		cout<<"//释放内存:"<<(strlen(m_data)+1)<<"B"<<endl;
		delete []m_data;
		init(another.m_data);
		return *this;
	}
	friend ostream &operator <<(ostream &os, const String &str);
	friend String operator +(const String &str1, const char *str2);

protected:
	String(const char *str1, const char *str2)
	{
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		cout<<"//申请内存:"<<(len1 + len2 + 1)<<"B"<<endl;
		m_data = new char[len1 + len2 + 1];
		cout<<"//内存拷贝"<<endl;
		strcpy(m_data, str1);
		strcat(m_data, str2);
	}
	inline void init(const char *str)
	{
		if(str == NULL)
		{
			cout<<"//申请内存:1B"<<endl;
			m_data = new char[1];
			m_data[0] = '\0';
		}
		else
		{
			int len = strlen(str);
			cout<<"//申请内存:"<<(len+1)<<"B"<<endl;
			m_data = new char[len+1];
			strcpy(m_data, str);
		}
	}

private:
	char *m_data;
};

ostream &operator <<(ostream &os, const String &str)
{
	os<<str.m_data;
	return os;
}

String operator +(const String &str1, const char *str2)
{
	return String(str1.m_data, str2);
}

int main()
{
	String str = "hello ";
	str = str + "world";
	cout<<str<<endl;
	return 0;
}
