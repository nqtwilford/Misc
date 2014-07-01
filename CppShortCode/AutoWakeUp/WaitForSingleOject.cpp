#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	HANDLE hTimer = CreateWaitableTimer(NULL, true, "wilfordwait");
	cout<<"wait for 10 second"<<endl;
	LARGE_INTEGER liDueTime;
	liDueTime.QuadPart = -600000000;	//��100����Ϊ��λ
	SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, true);

	if (WaitForSingleObject(hTimer, INFINITE) != WAIT_OBJECT_0)
        cout<<"WaitForSingleObject failed "<<GetLastError()<<endl;
    else 
		cout<<"Timer was signaled."<<endl;

	return 0;
}
