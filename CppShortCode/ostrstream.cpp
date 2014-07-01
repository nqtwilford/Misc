#include <iostream>
#include <strstream>
using namespace std;

int main()
{
	cout<<"type a int, a float and a string:"<<endl;
	int i;
	float f;
	cin>>i>>f;
	cin>>ws;
	char buf[100];
	cin.getline(buf, 100);
	ostrstream os(buf, 100, ios::app);
	os<<endl;
	os<<"integer = "<<i<<endl;
	os<<"float = "<<f<<endl;
	os<<ends;
	cout<<buf;
	cout<<os.rdbuf();
	cout<<os.rdbuf();
}
