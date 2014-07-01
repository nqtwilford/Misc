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
	D3DXMATRIX matRX;
	D3DXMatrixRotationX(&matRX, D3DX_PI/2);		//��Xת90��

	D3DXMATRIX matRY;
	D3DXMatrixRotationY(&matRY, D3DX_PI/2);	//��Y��ת90��

	D3DXVECTOR3 p(1.0f, 1.0f, 1.0f);
	D3DXVECTOR3 pNew;
	D3DXVec3TransformCoord(&pNew, &p, &matRX);
	D3DXVec3TransformCoord(&pNew, &pNew, &matRY);
	cout<<pNew.x<<" "<<pNew.y<<" "<<pNew.z<<endl;	//������Yת�������ƣ�ת���õ��Ľ���ǲ�һ����

	D3DXVec3TransformCoord(&pNew, &p, &matRY);
	D3DXVec3TransformCoord(&pNew, &pNew, &matRX);
	cout<<pNew.x<<" "<<pNew.y<<" "<<pNew.z<<endl;

	D3DXMATRIX matScaling;
	D3DXMatrixScaling(&matScaling, 2.0f, 3.0f, 2.0f);

	D3DXMATRIX matRXY = matScaling * matRX * matRY;
	D3DXVec3TransformCoord(&pNew, &p, &matRXY);
	cout<<pNew.x<<" "<<pNew.y<<" "<<pNew.z<<endl;	//������˵��Ӷ��Ч��,��˵Ĵ���Ϊ�任�Ĵ���

	D3DXMATRIX matRYX = matRY * matRX * matScaling;
	D3DXVec3TransformCoord(&pNew, &p, &matRYX);
	cout<<pNew.x<<" "<<pNew.y<<" "<<pNew.z<<endl;

	D3DXVec3TransformNormal(&pNew, &p, &matRXY);
	cout<<pNew.x<<" "<<pNew.y<<" "<<pNew.z<<endl;		//��ת��ı�����

	return 0;
}
