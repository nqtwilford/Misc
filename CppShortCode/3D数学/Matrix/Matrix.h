#ifndef MATRIX_H_
#define MATRIX_H_
class Matrix
{
public:
	Matrix();
	Matrix(float _11, float _12, float _13, float _14,
		     float _21, float _22, float _23, float _24,
		     float _31, float _32, float _33, float _34,
		     float _41, float _42, float _43, float _44);
	float &operator ()(int row, int col)
	{
		return m[row][col];
	}
	float operator ()(int row, int col) const
	{
		return m[row][col];
	}
	Matrix operator + (const Matrix &mat) const;
	Matrix operator - (const Matrix &mat) const;
	Matrix operator * (float f) const;
	Matrix operator * (const Matrix &mat) const;

	Matrix Transpose() const;
	Matrix Inverse() const;

	float m[4][4];
};

Matrix::Matrix()
{
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			m[i][j] = 0.0f;
}

Matrix::Matrix(float _11, float _12, float _13, float _14,
							 float _21, float _22, float _23, float _24,
							 float _31, float _32, float _33, float _34,
							 float _41, float _42, float _43, float _44)
{
	m[0][0] = _11; m[0][1] = _12; m[0][2] = _13; m[0][3] = _14; 
	m[1][0] = _21; m[1][1] = _22; m[1][2] = _23; m[1][3] = _24;
	m[2][0] = _31; m[2][1] = _32; m[2][2] = _33; m[2][3] = _34;
	m[3][0] = _41; m[3][1] = _42; m[3][2] = _43; m[3][3] = _44;
}

Matrix Matrix::operator + (const Matrix &mat) const
{
	return Matrix(m[0][0]+mat(0,0), m[0][1]+mat(0,1), m[0][2]+mat(0,2), m[0][3]+mat(0,3),
		            m[1][0]+mat(1,0), m[1][1]+mat(1,1), m[1][2]+mat(1,2), m[1][3]+mat(1,3),
		            m[2][0]+mat(2,0), m[2][1]+mat(2,1), m[2][2]+mat(2,2), m[2][3]+mat(2,3),
		            m[3][0]+mat(3,0), m[3][1]+mat(3,1), m[3][2]+mat(3,2), m[3][3]+mat(3,3));
}

Matrix Matrix::operator - (const Matrix &mat) const
{
	return Matrix(m[0][0]-mat(0,0), m[0][1]-mat(0,1), m[0][2]-mat(0,2), m[0][3]-mat(0,3),
		            m[1][0]-mat(1,0), m[1][1]-mat(1,1), m[1][2]-mat(1,2), m[1][3]-mat(1,3),
		            m[2][0]-mat(2,0), m[2][1]-mat(2,1), m[2][2]-mat(2,2), m[2][3]-mat(2,3),
		            m[3][0]-mat(3,0), m[3][1]-mat(3,1), m[3][2]-mat(3,2), m[3][3]-mat(3,3));
}

Matrix Matrix::operator * (float f) const
{
	return Matrix(m[0][0]*f, m[0][1]*f, m[0][2]*f, m[0][3]*f,
								m[1][0]*f, m[1][1]*f, m[1][2]*f, m[1][3]*f,
								m[2][0]*f, m[2][1]*f, m[2][2]*f, m[2][3]*f,
								m[3][0]*f, m[3][1]*f, m[3][2]*f, m[3][3]*f);
}
Matrix Matrix::operator * (const Matrix &mat) const
{
	return Matrix(m[0][0]*mat(0,0)+m[0][1]*mat(1,0)+m[0][2]*mat(2,0)+m[0][3]*mat(3,0),	//_11
		            m[0][0]*mat(0,1)+m[0][1]*mat(1,1)+m[0][2]*mat(2,1)+m[0][3]*mat(3,1),	//_12
								m[0][0]*mat(0,2)+m[0][1]*mat(1,2)+m[0][2]*mat(2,2)+m[0][3]*mat(3,2),	//_13
								m[0][0]*mat(0,3)+m[0][1]*mat(1,3)+m[0][2]*mat(2,3)+m[0][3]*mat(3,3),	//_14
								m[1][0]*mat(0,0)+m[1][1]*mat(1,0)+m[1][2]*mat(2,0)+m[1][3]*mat(3,0),	//_21
								m[1][0]*mat(0,1)+m[1][1]*mat(1,1)+m[1][2]*mat(2,1)+m[1][3]*mat(3,1),	//_22
								m[1][0]*mat(0,2)+m[1][1]*mat(1,2)+m[1][2]*mat(2,2)+m[1][3]*mat(3,2),	//_23
								m[1][0]*mat(0,3)+m[1][1]*mat(1,3)+m[1][2]*mat(2,3)+m[1][3]*mat(3,3),	//_24
								m[2][0]*mat(0,0)+m[2][1]*mat(1,0)+m[2][2]*mat(2,0)+m[2][3]*mat(3,0),	//_31
								m[2][0]*mat(0,1)+m[2][1]*mat(1,1)+m[2][2]*mat(2,1)+m[2][3]*mat(3,1),	//_32
								m[2][0]*mat(0,2)+m[2][1]*mat(1,2)+m[2][2]*mat(2,2)+m[2][3]*mat(3,2),	//_33
								m[2][0]*mat(0,3)+m[2][1]*mat(1,3)+m[2][2]*mat(2,3)+m[2][3]*mat(3,3),	//_34
								m[3][0]*mat(0,0)+m[3][1]*mat(1,0)+m[3][2]*mat(2,0)+m[3][3]*mat(3,0),	//_41
								m[3][0]*mat(0,1)+m[3][1]*mat(1,1)+m[3][2]*mat(2,1)+m[3][3]*mat(3,1),	//_42
								m[3][0]*mat(0,2)+m[3][1]*mat(1,2)+m[3][2]*mat(2,2)+m[3][3]*mat(3,2),	//_43
								m[3][0]*mat(0,3)+m[3][1]*mat(1,3)+m[3][2]*mat(2,3)+m[3][3]*mat(3,3));	//_44
}

Matrix Matrix::Transpose() const
{
	return Matrix(m[0][0], m[1][0], m[2][0], m[3][0], 
		            m[0][1], m[1][1], m[2][1], m[3][1], 
		            m[0][2], m[1][2], m[2][2], m[3][2], 
		            m[0][3], m[1][3], m[2][3], m[3][3]);
}
#include <d3dx9math.h>
Matrix Matrix::Inverse() const
{
	Matrix mat;
	D3DXMatrixInverse((D3DXMATRIX *)&mat, NULL, (D3DXMATRIX *)this);
	return mat;
}

#endif
