//3ά�����ļ򵥲���
#ifndef VECTOR3_H_
#define VECTOR3_H_
#include <cmath>
class Vector3
{
public:
	//constructors
	Vector3(): x(0.0f), y(0.0f), z(0.0f) {};
	Vector3(float x, float y, float z):
		x(x), y(y), z(z) {};

	//binary operators
	Vector3 operator + (const Vector3 &vec) const;
	Vector3 operator - (const Vector3 &vec) const;
	Vector3 operator * (float f) const;
	Vector3 operator / (float f) const;

	//functions
	//ģ���������ĳ���
	float Length() const;
	//��λ����ת��Ϊ����Ϊ1������
	Vector3 Normalize() const;
	//������������ģ�Ļ����ڼнǵ�����
	float Dot(const Vector3 &vec) const;
	//�����һ��ʹ�������������򣬵�DX��Ĭ��ʹ������
	//
	Vector3 Cross(const Vector3 &vec) const;
public:
	float x, y, z;
};

Vector3 Vector3::operator + (const Vector3 &vec) const
{	
	return Vector3(x+vec.x, y+vec.y, z+vec.z);
}

Vector3 Vector3::operator - (const Vector3 &vec) const
{
	return Vector3(x-vec.x, y-vec.y, z-vec.z);
}

Vector3 Vector3::operator * (float f) const
{
	return Vector3(x*f, y*f, z*f);
}
//�˷�������
Vector3 operator * (float f, const Vector3 &vec)
{
	return vec * f;
}

Vector3 Vector3::operator / (float f) const
{
	return Vector3(x/f, y/f, z/f);
}

//ģ
//��Ԫ��ƽ��֮�Ϳ���
float Vector3::Length() const
{
	return sqrt(x*x + y*y + z*z);
}

//��λ��
//��������ģ
Vector3 Vector3::Normalize() const
{
	return (*this) / Length();
}

//���
float Vector3::Dot(const Vector3 &vec) const
{
	return x*vec.x + y*vec.y + z*vec.z;
}

//�����ע�����
Vector3 Vector3::Cross(const Vector3 &vec) const
{
	return Vector3(y*vec.z-z*vec.y, z*vec.x-x*vec.z, 
		x*vec.y-y*vec.x);
}
#endif
