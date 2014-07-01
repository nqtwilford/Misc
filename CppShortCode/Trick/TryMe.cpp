#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
using namespace std;

bool FindAnother()
{
	int count = 0;
	HANDLE hps = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	PROCESSENTRY32 pe32 = {0};
	pe32.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hps, &pe32);
	do
	{
		if(strcmp(pe32.szExeFile,"TryMe.exe") == 0)
		{
			if(++count >= 2)
				return true;
		}
	}
	while(Process32Next(hps, &pe32));
	CloseHandle(hps);
	return false;
}

int main(void)
{
	cout<<"can you close me??"<<endl;
	while(true)
	{
		if(!FindAnother())
		{
			system("start TryMe.exe");
		}
		Sleep(200);
	}
	system("pause");
	return 0;
}
