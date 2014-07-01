#include "Matrix.h"
#include <iostream>
using namespace std;

ostream &operator << (ostream &os, const Matrix &mat)
{
	cout<<mat(0,0)<<"\t"<<mat(0,1)<<"\t"<<mat(0,2)<<"\t"<<mat(0,3)<<endl;
	cout<<mat(1,0)<<"\t"<<mat(1,1)<<"\t"<<mat(1,2)<<"\t"<<mat(1,3)<<endl;
	cout<<mat(2,0)<<"\t"<<mat(2,1)<<"\t"<<mat(2,2)<<"\t"<<mat(2,3)<<endl;
	cout<<mat(3,0)<<"\t"<<mat(3,1)<<"\t"<<mat(3,2)<<"\t"<<mat(3,3)<<endl;
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

	return 0;
}
