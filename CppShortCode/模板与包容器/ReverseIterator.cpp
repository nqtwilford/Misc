#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
//	typedef char MyType;
//	//读入内容
//	vector<MyType> vec;
//	copy(istream_iterator<MyType>(cin),
//		istream_iterator<MyType>(),
//		back_inserter(vec));
//	//反向回显
//	copy(vec.rbegin(), vec.rend(), 
//		ostream_iterator<MyType>(cout, ""));
//	cout<<endl;
//	//递减排序
//	sort(vec.rbegin(), vec.rend());
//	copy(vec.begin(), vec.end(), 
//		ostream_iterator<MyType>(cout, ""));
//	cout<<endl;
	//一个例子：输入一串逗号隔开的单词，取第一个和最后一个单词
	string str = "zhang,wei,wilford";
	string::const_iterator comma = find(str.begin(), str.end(), ',');
	cout<<string(static_cast<string::const_iterator>(str.begin()), comma);
	string::const_reverse_iterator rcomma = find(str.rbegin(), str.rend(), ',');
	cout<<string(rcomma.base(), static_cast<string::const_iterator>(str.end()));
	return 0;
}
