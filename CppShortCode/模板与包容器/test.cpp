#include <iostream>
#include <list>
using namespace std;

template <typename T>
void print(const T &val)
{
	cout<<val<<endl;
}

int main(int argc, char **argv)
{
	list<int> vec(10);
	for(int i = 1; i <= 3; ++i)
	{
		fill_n(front_inserter(vec), 2, i);
	}
	for_each(vec.begin(), vec.end(), print<int>);
	return EXIT_SUCCESS;
}
