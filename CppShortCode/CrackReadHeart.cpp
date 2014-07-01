#include <iostream>
using namespace std;
int fun(int a,int b)
{
	int w=(a*10+b)-(a+b);
	return w;

}
void main()
{
	for (int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			cout<<i<<"--"<<j<<"="<<fun(i,j)<<endl;
		}
	}
	system("pause");
}