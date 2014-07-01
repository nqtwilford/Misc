#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
	char c;
	vector<int> vec;
	vec.reserve(10);
	cout<<"size:\t"<<vec.size()<<endl;
	cout<<"capacity:\t"<<vec.capacity()<<endl;
	while(cin>>c)
	{
		if(c == 'i')
		{
			vec.push_back(1);
		}
		cout<<"size:\t"<<vec.size()<<endl;
		cout<<"capacity:\t"<<vec.capacity()<<endl;
	}
	return 0;
}
