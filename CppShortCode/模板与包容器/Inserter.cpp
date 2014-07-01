#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

template <class T>
void print(const T &val)
{
	cout<<val<<endl;
}

int main(int argc, char **argv)
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	list<int> lst;
	lst.push_back(0);
	lst.push_back(10);
	lst.push_back(20);

	list<int>::iterator iter = find(lst.begin(), lst.end(), 10);
	replace_copy(vec.begin(), vec.end(), inserter(lst, iter), 2, 200);	//插入时将2替换为200
	for_each(lst.begin(), lst.end(), print<int>);
	return 0;
}
