#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	HANDLE hTimer = CreateWaitableTimer(NULL, true, "wilfordwait");
	SYSTEMTIME sysTime = {0};
	sysTime.wYear = 2009;
	sysTime.wMonth = 12;
	sysTime.wDay = 19;
	sysTime.wHour = 13-8;
	sysTime.wMinute = 36;	

	FILETIME fileTime;
	SystemTimeToFileTime(&sysTime, &fileTime);

	LARGE_INTEGER liDueTime;
	liDueTime.LowPart = fileTime.dwLowDateTime;
	liDueTime.HighPart = fileTime.dwHighDateTime;
	SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, true);

	cout<<"waiting"<<endl;
	if (WaitForSingleObject(hTimer, INFINITE) != WAIT_OBJECT_0)
        cout<<"WaitForSingleObject failed "<<GetLastError()<<endl;
    else 
		cout<<"Timer was signaled."<<endl;

	return 0;
}
