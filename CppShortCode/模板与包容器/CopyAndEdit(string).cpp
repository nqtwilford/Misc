#include <iostream>
#include <string>
using namespace std;

class C1
{
public:
	string s;
};
int main()
{
/*
	C1 o1;
	o1.s = "Hello";
	C1 o2 = o1;
	//o1��o2ʹ����ͬ�Ļ�����
	cout<<(void *)o1.s.c_str()
		<<" "<<(void *)o2.s.c_str()<<endl;
	//ֱ�Ӷ�o2�Ļ��������в���������o1���ı�
	const_cast<char *>(o2.s.c_str())[1] = 'E';
	cout<<o1.s<<" "<<o2.s<<endl;
	//��o2��string����ִ�в���ʱ��o2��copy and edit
	o2.s[1] = 'O';
	//o1��o2����ʹ����ͬ�Ļ�������o1δ���ı�
	cout<<(void *)o1.s.c_str()
		<<" "<<(void *)o2.s.c_str()<<endl;
	cout<<o1.s<<" "<<o2.s<<endl;
*/

	string str1 = "Hello";
	string str2 = str1;
	//str1��str2ʹ����ͬ�Ļ�����
	cout<<static_cast<const void *>(str1.c_str())<<" "
		<<static_cast<const void *>(str2.c_str())<<endl;
	//ֱ�Ӷ�str2�Ļ��������в���������str1���ı�
	const_cast<char *>(str2.c_str())[1] = 'E';
	cout<<str1<<" "<<str2<<endl;
	//��str2������в���ʱ��str2��copy and edit
	str2[1] = 'O';
	//str1��str2����ʹ����ͬ�Ļ�������str1����δ���ı�
	cout<<static_cast<const void *>(str1.c_str())<<" "
		<<static_cast<const void *>(str2.c_str())<<endl;
	cout<<str1<<" "<<str2<<endl;
}
