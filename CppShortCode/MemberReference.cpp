//成员引用并不是真的引用
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
	cout<<x.i<<endl;	//输出了不确定的值，又是为何？？
	return 0;
}
