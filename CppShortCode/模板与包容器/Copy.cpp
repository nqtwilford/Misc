//查找names1和names2中共有的元素
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <numeric>
using namespace std;

template <class T>
void print(T val)
{
	cout<<val<<endl;
}

int main(int argc, char **argv)
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	list<double> lst;
	copy(vec.begin(), vec.end(), back_inserter(lst));
	for_each(vec.begin(), vec.end(), print<double>);
	cout<<"-----------"<<endl;
	replace_copy(vec.begin(), vec.end(), back_inserter(vec), 2, 4);
	for_each(vec.begin(), vec.end(), print<int>);
	//利用copy实现比for_each更简单的输入回显
	copy(istream_iterator<string>(cin),
		istream_iterator<string>(),
		ostream_iterator<string>(cout, "\n"));
	return EXIT_SUCCESS;
}
