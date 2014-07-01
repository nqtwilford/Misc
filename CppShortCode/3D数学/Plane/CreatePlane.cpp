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
	//3点创建平面
	D3DXPlaneFromPoints(&plane, &p0, &p1, &p2);
	cout<<plane<<endl;
	//由点和法线创建平面
	D3DXVECTOR3 normal(1.0f, 1.0f, 1.0f);
	D3DXPlaneFromPointNormal(&plane, &p0, &normal);
	cout<<plane<<endl;
	//求直线和平面的交点
	D3DXVECTOR3 pIntersect;
	D3DXPlaneIntersectLine(&pIntersect, &plane, &(D3DXVECTOR3(-1,-1,-1)), &(D3DXVECTOR3(1,1,1)));
	cout<<pIntersect<<endl;
	//点与平面的点积,如果<0点在平面另一侧，=0点在平面上，>0点在平面同一侧
	D3DXVECTOR3 p3(1.0f, 1.0f, 1.0f);
	if(D3DXPlaneDotCoord(&plane, &p3) > 0)
	{
		cout<<"点:"<<p3<<"与平面:"<<plane<<"在同一侧"<<endl;
	}
	D3DXVECTOR3 p4(0.1f, 0.1f, 0.1f);
	if(D3DXPlaneDotCoord(&plane, &p4) < 0)
	{
		cout<<"点:"<<p4<<"在平面:"<<plane<<"另一侧"<<endl;
	}
	//平面的单位化,单位化后的平面与点的点积即为点到平面的有向距离
	D3DXPLANE normalizedPlane;
	D3DXPlaneNormalize(&normalizedPlane, &plane);
	cout<<normalizedPlane<<endl;
	cout<<"点:"<<p4<<"到平面:"<<normalizedPlane<<"的有向距离为:"<<D3DXPlaneDotCoord(&normalizedPlane, &p4)<<endl;

	return 0;
}
