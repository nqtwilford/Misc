#include "Vector3.h"
#include <iostream>
using namespace std;

ostream &operator << (ostream &os, const Vector3 &vec)
{
	return os<<"("<<vec.x<<", "<<vec.y<<", "<<vec.z<<")";
}

int main(int argc, char *argv[])
{
	Vector3 vec1(1.1f, 2.2f, 3.3f);
	Vector3 vec2(4.4f, 5.5f, 6.6f);
	Vector3 vec3 = vec1 + vec2;
	Vector3 vec4 = vec3 - vec1;
	cout<<vec3<<endl;
	cout<<vec4<<endl;
	return 0;
}
