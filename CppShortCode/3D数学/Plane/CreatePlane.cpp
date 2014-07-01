#include <d3dx9math.h>
#include <iostream>
using namespace std;

ostream &operator << (ostream &os, const D3DXPLANE &plane)
{
	return os<<plane.a<<"x+"<<plane.b<<"y+"<<plane.c<<"z+"<<plane.d<<"=0";
}

ostream &operator << (ostream &os, const D3DXVECTOR3 &vec)
{
	return os<<"("<<vec.x<<", "<<vec.y<<", "<<vec.z<<")";
}

int main(int argc, char *argv[])
{
	D3DXVECTOR3 p0(1.0f, 0.0f, 0.0f);
	D3DXVECTOR3 p1(0.0f, 1.0f, 0.0f);
	D3DXVECTOR3 p2(0.0f, 0.0f, 1.0f);
	D3DXPLANE plane;
	//3�㴴��ƽ��
	D3DXPlaneFromPoints(&plane, &p0, &p1, &p2);
	cout<<plane<<endl;
	//�ɵ�ͷ��ߴ���ƽ��
	D3DXVECTOR3 normal(1.0f, 1.0f, 1.0f);
	D3DXPlaneFromPointNormal(&plane, &p0, &normal);
	cout<<plane<<endl;
	//��ֱ�ߺ�ƽ��Ľ���
	D3DXVECTOR3 pIntersect;
	D3DXPlaneIntersectLine(&pIntersect, &plane, &(D3DXVECTOR3(-1,-1,-1)), &(D3DXVECTOR3(1,1,1)));
	cout<<pIntersect<<endl;
	//����ƽ��ĵ��,���<0����ƽ����һ�࣬=0����ƽ���ϣ�>0����ƽ��ͬһ��
	D3DXVECTOR3 p3(1.0f, 1.0f, 1.0f);
	if(D3DXPlaneDotCoord(&plane, &p3) > 0)
	{
		cout<<"��:"<<p3<<"��ƽ��:"<<plane<<"��ͬһ��"<<endl;
	}
	D3DXVECTOR3 p4(0.1f, 0.1f, 0.1f);
	if(D3DXPlaneDotCoord(&plane, &p4) < 0)
	{
		cout<<"��:"<<p4<<"��ƽ��:"<<plane<<"��һ��"<<endl;
	}
	//ƽ��ĵ�λ��,��λ�����ƽ�����ĵ����Ϊ�㵽ƽ����������
	D3DXPLANE normalizedPlane;
	D3DXPlaneNormalize(&normalizedPlane, &plane);
	cout<<normalizedPlane<<endl;
	cout<<"��:"<<p4<<"��ƽ��:"<<normalizedPlane<<"���������Ϊ:"<<D3DXPlaneDotCoord(&normalizedPlane, &p4)<<endl;

	return 0;
}
