#include <stdio.h>
#include <stdlib.h>

double *matrixreverse(double A[], int m, int n);
double *matrixinver(double A[], int m, int n);
double surplus(double A[], int m, int n) ;

int main()
{
	int m = 3, n = 3;
	double* A = NULL;
	double* RST = NULL;
	A = (double*)malloc(m * n * sizeof(double));
	RST =  (double*)malloc(m * n * sizeof(double));
	for (int i = 0; i < m * n; i++)
	{
		scanf("%lf", &A[i]);
	}

	RST = matrixreverse(A, m, n);

	for (int i = 0; i < m * n; i++)
	{
		printf("%lf\t", RST[i]);
	}

	printf("\n");
	//system("pause");
	return 0;
}

double *matrixreverse(double A[], int m, int n) /*矩阵求逆*/
{
	int i, j, x, y, k;
	double *SP = NULL, *AB = NULL, *B = NULL, X, *C;
	SP = (double*)malloc(m * n * sizeof(double));
	AB = (double*)malloc(m * n * sizeof(double));
	B = (double*)malloc(m * n * sizeof(double));

	X = surplus(A,m,n);
	X = 1 / X;
	for (i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < m * n; k++)
				B[k] = A[k];
			{
				for(x = 0; x < n; x++)
					B[i * n + x] = 0;
				for(y = 0; y < m; y++)
					B[m * y + j] = 0;
				B[i * n + j] = 1;
				SP[i * n + j] = surplus(B, m, n);
				AB[i * n + j] = X * SP[i * n + j];
			}
		}
		C = matrixinver(AB, m, n);

		return C;
}

double *matrixinver(double A[], int m, int n) /*矩阵转置*/
{
	int i, j;
	double *B = NULL;
	B =(double*)malloc(m * n * sizeof(double));

	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			B[i * m + j] = A[j * n + i];
	return B;
}

double surplus(double A[], int m, int n) /*求矩阵行列式*/
{
	int i, j, k, p, r;
	double X, temp = 1, temp1 = 1, s = 0, s1 = 0;

	if (n == 2)
	{
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				if ((i + j) % 2) 
					temp1 *= A[i * n + j];
				else 
					temp *= A[i * n + j];
		X = temp - temp1;
	}
	else
	{
		for (k = 0; k < n; k++)
		{
			for (i = 0, j = k; i < m, j < n; i++, j++)
				temp *= A[i * n + j];
			if (m - i)
			{
				for (p = m - i, r = m - 1; p > 0; p--, r--)
					temp *= A[r * n + p - 1];
			}
			s += temp;
			temp = 1;
		}

		for (k = n - 1; k >= 0; k--)
		{
			for (i = 0, j = k; i < m, j >= 0; i++, j--)
				temp1 *= A[i * n + j];
			if (m - i)
			{
				for (p = m - 1, r = i; r < m; p--, r++)
					temp1 *= A[r * n + p];
			}
			s1 += temp1;
			temp1 = 1;
		}

		X = s - s1;
	}

	return X;
}
