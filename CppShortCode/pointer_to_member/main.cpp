#include <iostream>
using namespace std;

struct Vec2
{
	float x, y;
};

int main()
{
	float Vec2::*m = &Vec2::y;
	Vec2 vec;
	vec.x = 10.f;
	vec.y = 20.f;
	vec.*m -= 5.f;
	cout<<vec.x<<" "<<vec.y<<endl;
	return 0;
}
