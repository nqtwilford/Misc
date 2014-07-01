#include<iostream>
#include<cmath>
#include<ctime>
#define COUNT 500000000 //ѭ��ȡ������
using namespace std;

bool InCircle(double x,double y)//�Ƿ���1/4Բ��Χ֮��
{
	if((x*x+y*y)<=1)return true;
	return false;
}
int main()
{
	double x,y;
	int num=0;
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<COUNT;i++)
	{
		x=rand()*1.0/RAND_MAX;
		y=rand()*1.0/RAND_MAX;
		if(InCircle(x,y)) num++;
	}
	cout<<"PI:"<<(num*4.0)/COUNT<<endl;
	return 0;
} 
