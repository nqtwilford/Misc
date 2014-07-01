#include <map>
#include <iostream>
using namespace std;

int main()
{
	const map<int, int> iimap;
	//iimap[0] = 10;
	//iimap[1] = 11;
	auto itr = iimap.find(2);
	cout<<"itr == end():"<<(itr == iimap.end())<<endl;
	cout<<"itr == cend():"<<(itr == iimap.cend())<<endl;
	return 0;
}
