#include <iostream>
#include "C.h"
using namespace std;

int main()
{
	C c(1);
	cout<<c.Geti()<<'\n';
	int &i = c.Geti();
	++i;
	cout<<c.Geti()<<'\n';
	return 0;
}
