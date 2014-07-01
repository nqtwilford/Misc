#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int ival;
	while(cin>>ival, !cin.eof())
	{
		if(cin.fail())
		{
			cout<<"bad input"<<endl;
			cin.clear();
			cin.sync();
		}
	}
	return 0;
}
