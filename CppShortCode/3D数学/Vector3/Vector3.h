//3维向量的简单操作
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
	//模，即向量的长度
	float Length() const;
	//单位化，转化为长度为1的向量
	Vector3 Normalize() const;
	//点积，点积除以模的积等于夹角的余弦
	float Dot(const Vector3 &vec) const;
	//叉积，一般使用右手螺旋法则，但DX中默认使用左手
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
//乘法交换律
Vector3 operator * (float f, const Vector3 &vec)
{
	return vec * f;
}

Vector3 Vector3::operator / (float f) const
{
	return Vector3(x/f, y/f, z/f);
}

//模
//各元素平方之和开方
float Vector3::Length() const
{
	return sqrt(x*x + y*y + z*z);
}

//单位化
//向量除以模
Vector3 Vector3::Normalize() const
{
	return (*this) / Length();
}

//点积
float Vector3::Dot(const Vector3 &vec) const
{
	return x*vec.x + y*vec.y + z*vec.z;
}

//叉积，注意规律
Vector3 Vector3::Cross(const Vector3 &vec) const
{
	return Vector3(y*vec.z-z*vec.y, z*vec.x-x*vec.z, 
		x*vec.y-y*vec.x);
}
#endif
