#include <iostream>
using namespace std;

class String
{
public:
	String()	//�޲�������
	{
		cout<<"//�޲�������"<<endl;
		cout<<"//�����ڴ�:1B"<<endl;
		m_data = new char[1];
		m_data[0] = '\0';
	}
	String(const char *str)		//����������
	{
		cout<<"//����������"<<endl;
		init(str);
	}
	String(const String &another)	//��������
	{
		cout<<"//��������"<<endl;
		init(another.m_data);
	}
	~String()
	{
		cout<<"//�ͷ��ڴ�:"<<(strlen(m_data)+1)<<"B"<<endl;
		delete []m_data;
	}
	String &operator =(const String &another)	//��ֵ
	{
		cout<<"//��ֵ"<<endl;
		if(this == &another)	//����Ը�ֵ���ǳ���Ҫ
			return *this;

		cout<<"//�ͷ��ڴ�:"<<(strlen(m_data)+1)<<"B"<<endl;
		delete []m_data;
		init(another.m_data);
		return *this;
	}
	operator const char *() const	//�Զ�����ת�������
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
			cout<<"//�����ڴ�:1B"<<endl;
			m_data = new char[1];
			m_data[0] = '\0';
		}
		else
		{
			int len = strlen(str);
			cout<<"//�����ڴ�:"<<(len+1)<<"B"<<endl;
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
	cout<<"//�ͷ��ڴ�:"<<(strlen(strTemp.m_data)+1)<<"B"<<endl;
	delete []strTemp.m_data;
	cout<<"//�����ڴ�:"<<(len1 + len2 + 1)<<"B"<<endl;
	strTemp.m_data = new char[len1 + len2 + 1];
	cout<<"//�ڴ濽��"<<endl;
	strcpy(strTemp.m_data, str1.m_data);
	strcat(strTemp.m_data, str2);
	return strTemp;
}

//String &operator +(const String &str1, const char *str2)
//{
//	int len1 = strlen(str1.m_data);
//	int len2 = strlen(str2);
//	String *strTemp = new String;
//	cout<<"//�ͷ��ڴ�:"<<(strlen(strTemp->m_data)+1)<<"B"<<endl;
//	delete []strTemp->m_data;
//	cout<<"//�����ڴ�:"<<(len1 + len2 + 1)<<"B"<<endl;
//	strTemp->m_data = new char[len1 + len2 + 1];
//	cout<<"//�ڴ濽��"<<endl;
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
