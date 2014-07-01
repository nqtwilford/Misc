//只能在堆上创建的String类
#ifndef STRING_H_
#define STRING_H_
#include <iostream>
using namespace std;
class String
{
public:
	friend String *MakeString(const char *str)
	{
		return new String(str);
	}
	static String *Make(const char *str)
	{
		return new String(str);
	}
	~String()
	{
		delete[] m_str;
	}
	const char *str() const
	{
		return m_str;
	}
	operator const char *() const
	{
		m_str[0] = '&';
		return m_str;
	}
	//在做cout输出时，下面这个会首先使用，如果没有定义下面这个
	//则会使用上面的类型转换运算符
//	friend ostream &operator<<(ostream &os, const String &str)
//	{
//		return os<<str.m_str<<"from friend";
//	}
private:
	String(const char *str)
	{
		m_str = new char[strlen(str)+1];
		strcpy(m_str, str);
	}
	String(const String &);
	String &operator=(const String &);

	char * m_str;
};
#endif
