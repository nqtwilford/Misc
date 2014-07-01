#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	ostringstream os;
	os<<"fsdfsd "<<5;
	cout<<os.str()<<endl;
	os<<"haha";
	cout<<os.str()<<endl;

	istringstream is("1.414 2 this and");
	int i;
	float f;
	string str;
	is>>f>>i>>str;
	cout<<i<<" "<<f<<" "<<str<<endl;
	return 0;
}
