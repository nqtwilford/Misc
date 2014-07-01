#define NDEBUG		//If not debugging, assert does nothing
#include <iostream>
#include <iomanip>
#include <sstream>
#include <assert.h>
using namespace std;

#define DEBUG(X) cout<<#X" = "<<X<<'\n';	//����̨���һ��������ֵ
#define TRACE(X) cout<<#X<<'\n', X;			//����̨�����䣬��ִ����䡣��������ʾ���δ����
#define FIELD(X) char *sz##X; int i##X;		

int main()
{
	int i = 3;
	assert( i == 4);
	void();
	DEBUG(i);
	if(i == 4)
		TRACE(++i);		//����ʹ���ˡ��������Ա�֤���ڵ�������䶼λ��if����
	DEBUG(i);
	FIELD(Test);
	DEBUG(szTest);
	DEBUG(iTest);
	return 0;
}
