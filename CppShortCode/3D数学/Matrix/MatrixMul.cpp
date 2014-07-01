#include "Matrix.h"
#include <iostream>
using namespace std;

ostream &operator << (ostream &os, const Matrix &mat)
{
	os<<mat(0,0)<<"\t"<<mat(0,1)<<"\t"<<mat(0,2)<<"\t"<<mat(0,3)<<endl;
	os<<mat(1,0)<<"\t"<<mat(1,1)<<"\t"<<mat(1,2)<<"\t"<<mat(1,3)<<endl;
	os<<mat(2,0)<<"\t"<<mat(2,1)<<"\t"<<mat(2,2)<<"\t"<<mat(2,3)<<endl;
	os<<mat(3,0)<<"\t"<<mat(3,1)<<"\t"<<mat(3,2)<<"\t"<<mat(3,3)<<endl;
	return os;
}

int main(int argc, char *argv[])
{
	Matrix mat1(1,2,3,4,
							5,6,7,8,
							9,1,2,3,
							4,5,6,7);
	Matrix mat2(1,2,3,4,
							5,6,7,8,
							9,1,2,3,
							4,5,6,7);
	Matrix mat3 = mat1 + mat2;
	Matrix mat4 = mat1 - mat2;
	cout<<mat3<<endl;
	cout<<mat4<<endl;
	cout<<mat3*0.5<<endl;
	Matrix matU(11,12,13,14,
		          21,22,23,24,
		          31,32,33,34,
		          41,42,43,44);
	Matrix matV(-10,-12,-13,-14,
		          -21,-21,-23,-24,
		          -31,-32,-32,-34,
		          -41,-42,-43,-43);
	cout<<matU*matV<<endl;

	return 0;
}
