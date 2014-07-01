#include <sstream>
#include <windows.h>
#include <tlhelp32.h>
using namespace std;
#include <iostream>

int main(int argn, char **args)
{
	if(argn < 2) return 0;
	char   fname[_MAX_FNAME];
	char   ext[_MAX_EXT];
	_splitpath(args[1], NULL, NULL, fname, ext); 
	ostringstream filename;
	filename<<fname<<ext;

	HANDLE hps = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);

	Process32First(hps, &pe);
	
	do
	{
		if(strcmp(pe.szExeFile, filename.str().c_str()) == 0)
		{
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, TRUE, pe.th32ProcessID);
			if(hProcess!=NULL)
		    {
				TerminateProcess(hProcess,0);
				CloseHandle(hProcess);
			}
		}
	}
	while(Process32Next(hps, &pe));
	CloseHandle(hps);
}
