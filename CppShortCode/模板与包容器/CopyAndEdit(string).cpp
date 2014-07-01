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
	//o1和o2使用相同的缓冲区
	cout<<(void *)o1.s.c_str()
		<<" "<<(void *)o2.s.c_str()<<endl;
	//直接对o2的缓冲区进行操作，导致o1被改变
	const_cast<char *>(o2.s.c_str())[1] = 'E';
	cout<<o1.s<<" "<<o2.s<<endl;
	//对o2的string对象执行操作时，o2会copy and edit
	o2.s[1] = 'O';
	//o1和o2不再使用相同的缓冲区，o1未被改变
	cout<<(void *)o1.s.c_str()
		<<" "<<(void *)o2.s.c_str()<<endl;
	cout<<o1.s<<" "<<o2.s<<endl;
*/

	string str1 = "Hello";
	string str2 = str1;
	//str1和str2使用相同的缓冲区
	cout<<static_cast<const void *>(str1.c_str())<<" "
		<<static_cast<const void *>(str2.c_str())<<endl;
	//直接对str2的缓冲区进行操作，导致str1被改变
	const_cast<char *>(str2.c_str())[1] = 'E';
	cout<<str1<<" "<<str2<<endl;
	//对str2对象进行操作时，str2会copy and edit
	str2[1] = 'O';
	//str1和str2不在使用相同的缓冲区，str1对象未被改变
	cout<<static_cast<const void *>(str1.c_str())<<" "
		<<static_cast<const void *>(str2.c_str())<<endl;
	cout<<str1<<" "<<str2<<endl;
}
