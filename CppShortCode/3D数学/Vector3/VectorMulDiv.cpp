#include "Vector3.h"
#include <iostream>
using namespace std;

ostream &operator << (ostream &os, const Vector3 &vec)
{
	return os<<"("<<vec.x<<", "<<vec.y<<", "<<vec.z<<")";
}

int main(int argc, char *argv[])
{
	Vector3 vec1(0.2f, 1.1f, 0.5f);
	cout<<vec1*2.0f<<endl;
	cout<<vec1/3.0f<<endl;
	return 0;
}
