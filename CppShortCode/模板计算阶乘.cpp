#include <iostream>
using namespace std;

template <int n>
class fact
{
public:
	static int var;
};
template <int n>
int fact<n>::var = n*fact<n - 1>::var;

template <>
class fact<1>
{
public:
	static int var;
};
template <>
int fact<1>::var = 1;

int main()
{
	const int n = 9;
	cout<<fact<n>::var<<endl;
	return 0;
}
