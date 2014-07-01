#include <d3dx9math.h>
#include <iostream>
using namespace std;

ostream &operator << (ostream &os, const D3DXMATRIX &mat)
{
	os<<mat(0,0)<<"\t"<<mat(0,1)<<"\t"<<mat(0,2)<<"\t"<<mat(0,3)<<endl;
	os<<mat(1,0)<<"\t"<<mat(1,1)<<"\t"<<mat(1,2)<<"\t"<<mat(1,3)<<endl;
	os<<mat(2,0)<<"\t"<<mat(2,1)<<"\t"<<mat(2,2)<<"\t"<<mat(2,3)<<endl;
	os<<mat(3,0)<<"\t"<<mat(3,1)<<"\t"<<mat(3,2)<<"\t"<<mat(3,3)<<endl;
	return os;
}

int main(int argc, char *argv[])
{
	D3DXMATRIX matTranslation;
	D3DXMatrixTranslation(&matTranslation, 1.0f, 2.0f, 3.0f);
	cout<<matTranslation<<endl;

	D3DXVECTOR3 p(15.0f, 3.0f, -1.9f);
	D3DXVECTOR3 pNew;
	D3DXVec3TransformCoord(&pNew, &p, &matTranslation);
	cout<<pNew.x<<" "<<pNew.y<<" "<<pNew.z<<endl;

	D3DXVec3TransformNormal(&pNew, &p, &matTranslation);
	cout<<pNew.x<<" "<<pNew.y<<" "<<pNew.z<<endl;		//平移不会改变向量

	return 0;
}
