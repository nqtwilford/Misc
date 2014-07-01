#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	const int ci = 1;
//	int *j = &ci;		//illegal
//	int *j = (int *)&ci;	//legal but deprecated
	int *j = const_cast<int *>(&ci);
	//illegal can't do type conversion additionally
//	long *l = const_cast<long *>(&ci);
	return 0;
}
