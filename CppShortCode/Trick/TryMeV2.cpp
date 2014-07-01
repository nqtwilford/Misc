#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

using namespace std;

bool FindAnother()
{
	
	HANDLE hps = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);

	Process32First(hps, &pe);
	
	int count = 0;
	bool found = false;
	do
	{
		if(strcmp(pe.szExeFile, "taskmgr.exe") == 0)	//如果检测到任务管理器打开，结束之
		{
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, TRUE, pe.th32ProcessID);
			if(hProcess!=NULL)
		    {
				TerminateProcess(hProcess,0);
				CloseHandle(hProcess);
			}
		}
		else if(strcmp(pe.szExeFile, "TryMeV2.exe") == 0)
		{
			if(++count >= 2)
				found = true;
		}
	}
	while(Process32Next(hps, &pe));
	CloseHandle(hps);

	return found;
}

int main()
{
	cout<<"Can you close me??"<<endl;
	while(true)
	{
		if(!FindAnother())
		{
			system("start TryMeV2.exe");
		}
		Sleep(200);
	}
}
