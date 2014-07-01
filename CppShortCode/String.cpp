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
	operator const char *() const	//自动类型转换运算符
	{
		return m_data;
	}
	friend ostream &operator <<(ostream &os, const String &str);
	friend String operator +(const String &str1, const char *str2);

protected:
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
	int len1 = strlen(str1.m_data);
	int len2 = strlen(str2);
	String strTemp;
	cout<<"//释放内存:"<<(strlen(strTemp.m_data)+1)<<"B"<<endl;
	delete []strTemp.m_data;
	cout<<"//申请内存:"<<(len1 + len2 + 1)<<"B"<<endl;
	strTemp.m_data = new char[len1 + len2 + 1];
	cout<<"//内存拷贝"<<endl;
	strcpy(strTemp.m_data, str1.m_data);
	strcat(strTemp.m_data, str2);
	return strTemp;
}

//String &operator +(const String &str1, const char *str2)
//{
//	int len1 = strlen(str1.m_data);
//	int len2 = strlen(str2);
//	String *strTemp = new String;
//	cout<<"//释放内存:"<<(strlen(strTemp->m_data)+1)<<"B"<<endl;
//	delete []strTemp->m_data;
//	cout<<"//申请内存:"<<(len1 + len2 + 1)<<"B"<<endl;
//	strTemp->m_data = new char[len1 + len2 + 1];
//	cout<<"//内存拷贝"<<endl;
//	strcpy(strTemp->m_data, str1.m_data);
//	strcat(strTemp->m_data, str2);
//	return *strTemp;
//}

int main()
{
	String str = "hello ";
	str = str + "world";
	cout<<str<<endl;
//	const char *str1 = str;
	str = str + "\n";
	printf(str);
	return 0;
}
