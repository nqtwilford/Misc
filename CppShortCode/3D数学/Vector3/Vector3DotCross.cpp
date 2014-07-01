#include "Vector3.h"
#include <iostream>
using namespace std;

ostream &operator << (ostream &os, const Vector3 &vec)
{
	return os<<"("<<vec.x<<", "<<vec.y<<", "<<vec.z<<")";
}

int main(int argc, char *argv[])
{
	Vector3 vecx(1.0f, 0.0f, 0.0f);
	Vector3 vecy(0.0f, 1.0f, 0.0f);
	Vector3 vecz(0.0f, 0.0f, 1.0f);
	cout<<vecx.Dot(vecy)<<endl;		//x���y�ᴹֱ�����Ϊ��
	cout<<vecx.Cross(vecy)<<endl;	//x Cross y = z
	cout<<vecz.Cross(vecz)<<endl;	//ƽ���������Ϊ������

	Vector3 vecU(2.3f, 4.7f, -5.3f);
	Vector3 vecV(5.2f, -1.7f, 2.9f);
	Vector3 vecW = vecU.Cross(vecV);
	cout<<vecW.Dot(vecU)<<" "<<vecW.Dot(vecV)<<endl;	//both ��0
	cout<<vecW<<" "<<vecW.Normalize()<<endl;	//U��V�Ĳ�����ǵ�λ����
	float sinAlpha = 1 - vecU.Dot(vecV) / (vecU.Length()*vecV.Length());
	cout<<vecW.Length()<<" "<<vecU.Length()*vecV.Length()*sinAlpha<<endl;//|W| != |U||V|sin��
	
	return 0;
}
