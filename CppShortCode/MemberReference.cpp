//��Ա���ò������������
#include <iostream>
using namespace std;
class X
{
public:
	X(int j) : i(j){}
	int &i;
};
int main()
{
	int i = 3;
	X x(i);
	cout<<x.i<<endl;
	x.i = 4;
	cout<<i<<endl;	//still 3, not 4
	i = 5;
	cout<<x.i<<endl;	//����˲�ȷ����ֵ������Ϊ�Σ���
	return 0;
}
