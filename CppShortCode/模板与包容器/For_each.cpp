#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template <class T>
void Print(const T &val)
{
	cout<<val<<endl;
}

int main(int argc, char **argv)
{
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
	for_each(vec.begin(), vec.end(), Print<int>);
	//利用for_each,最简单的输入回显
	for_each(istream_iterator<string>(cin),
		istream_iterator<string>(),Print<string>);
	return 0;
}
