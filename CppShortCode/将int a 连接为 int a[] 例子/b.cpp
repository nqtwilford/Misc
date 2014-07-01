#include <iostream>
using namespace std;

int main()
{
	cout<<"before"<<"\n";
	extern int *array;
	cout<<"after"<<'\n';
	cout<<array<<'\n';
	return 0;
}
