#define NDEBUG		//If not debugging, assert does nothing
#include <iostream>
#include <iomanip>
#include <sstream>
#include <assert.h>
using namespace std;

#define DEBUG(X) cout<<#X" = "<<X<<'\n';	//控制台输出一个变量的值
#define TRACE(X) cout<<#X<<'\n', X;			//控制台输出语句，并执行语句。“，”表示语句未结束
#define FIELD(X) char *sz##X; int i##X;		

int main()
{
	int i = 3;
	assert( i == 4);
	void();
	DEBUG(i);
	if(i == 4)
		TRACE(++i);		//由于使用了“，”可以保证宏内的所有语句都位于if块内
	DEBUG(i);
	FIELD(Test);
	DEBUG(szTest);
	DEBUG(iTest);
	return 0;
}
