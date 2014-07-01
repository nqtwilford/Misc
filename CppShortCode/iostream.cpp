#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

int main()
{
//	cout<<oct<<"0x"<<12345<<endl;	//16进制输出输出

//	char str[200];
//	cin.getline(str, 10);			//可接收空格
//	cout<<str<<endl;

//	string str1;
//	getline(cin, str1);
//	cout<<str1<<endl;				//可接收空格

	ifstream in("iostream.cpp");
	assert(in);
	cout<<in.rdbuf();

	return 0;
}
