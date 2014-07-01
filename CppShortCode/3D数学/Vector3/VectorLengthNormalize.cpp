#include "Vector3.h"
#include <iostream>
using namespace std;

ostream &operator << (ostream &os, const Vector3 &vec)
{
	return os<<"("<<vec.x<<", "<<vec.y<<", "<<vec.z<<")";
}

int main(int argc, char *argv[])
{
	Vector3 vec2(23.0f, 3.8f, -12.3f);
	cout<<vec2.Length()<<endl;
	Vector3 vecNor = vec2.Normalize();
	cout<<vecNor<<endl;
	cout<<vecNor.Length()<<endl;
	return 0;
}
