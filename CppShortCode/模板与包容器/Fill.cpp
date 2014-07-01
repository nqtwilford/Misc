//查找names1和names2中共有的元素
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

template <class T>
void print(T val)
{
	cout<<val<<endl;
}

int main(int argc, char **argv)
{
	vector<double> vec;
	vec.push_back(0.1);
	vec.push_back(0.2);
	vec.push_back(0.3);

	*vec.end() = 10;

	cout<<*vec.end()<<endl;
	//fill会写超出范围的元素，与书上的描述不同
	//在mingw中会修改掉不该修改的元素，在vc中会崩溃
	fill(vec.begin(), vec.end()+1, 0);
	cout<<*vec.end()<<endl;
	for_each(vec.begin(), vec.end(), print<double>);

	//fill_n也会写超出范围的元素
	*vec.end() = 10;
	fill_n(vec.begin(), 4, 0);
	cout<<*vec.end()<<endl;

//	//可以使用back_inserter后部插入
	fill_n(back_inserter(vec), 3, 1);
	for_each(vec.begin(), vec.end(), print<vector<double>::value_type>);

	return EXIT_SUCCESS;
}
