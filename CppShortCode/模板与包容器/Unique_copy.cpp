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
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(3);

	vector<int> vec2;
	unique_copy(vec.begin(), vec.end(), back_inserter(vec2));
	
	for_each(vec2.begin(), vec2.end(), print<int>);
	return 0;
}
