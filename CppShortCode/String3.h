//ֻ���ڶ��ϴ�����String��
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
	//����cout���ʱ���������������ʹ�ã����û�ж����������
	//���ʹ�����������ת�������
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
