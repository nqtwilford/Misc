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
	Matrix mat(1, 2, 3, 0,
		         2, 1, 2, 0,
		         1, 3, 4, 0,
		         0, 0, 0, 0);
	cout<<mat.Inverse()<<endl;
	return 0;
}
