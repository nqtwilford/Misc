#define WINVER 0x0601

#include <iostream>
//#include <lua.hpp>
#include <windows.h>
#include <PowrProf.h>
#include "EpLuaScriptEngine.h"
using namespace std;

EpLuaScriptEngine epLua;

bool bUseAbsolute;
LARGE_INTEGER liDueTime;
int iComNum = 0;
const int iMaxComNum = 10;
char *szCommands[iMaxComNum];
bool bAutoSleep;		//�Ƿ��Զ�˯��
int  iSleepAction;		//1:Sleep 2:Hibernate
bool bSUseAbsolute;		//˯�߶�ʱ�Ƿ�ʹ�þ���ʱ��
LARGE_INTEGER liSDueTime;	//˯�ߵĶ�ʱʱ��

bool LoadConfig(const char *fileName);
bool LoadWakeUpTime();
bool LoadSleepTime();
void ExecuteCommands();

bool LoadConfig(const char *fileName)
{
	if(!epLua.LoadScript(fileName))
	{
		cout<<"���������ļ�:"<<fileName<<"ʧ��"<<endl;
		return false;
	}
	//��ȡ����ʱ��
	if(!LoadWakeUpTime())
	{
		return false;
	}
	//��ȡ��Ҫִ�е����lua�������±��1��ʼ
	for(int i = 1; i <= iMaxComNum; ++i)
	{
		const char *str;
		if(epLua.GetTString("Commands", i, &str))
		{
			szCommands[iComNum] = new char[strlen(str)+1];
			strcpy(szCommands[iComNum], str);
			++iComNum;
		}
		else
		{
			break;
		}
	}
	//��ȡ˯��ʱ��
	bAutoSleep = LoadSleepTime();
	if(bAutoSleep)
		cout<<"�����Զ�˯��"<<endl;
	else
		cout<<"�������Զ�˯��"<<endl;
	return true;
}

bool LoadWakeUpTime()
{
	if(!epLua.GetBool("UseAbsolute", &bUseAbsolute))
	{
		cout<<"UseAbsolute??"<<endl;
		return false;
	}
	if(bUseAbsolute)
	{
		int year;
		if(!epLua.GetInt("Year", &year))
		{
			cout<<"Year??"<<endl;
			return false;
		}
		int month;
		if(!epLua.GetInt("Month", &month))
		{
			cout<<"Month??"<<endl;
			return false;
		}
		int day;
		if(!epLua.GetInt("Day", &day))
		{
			cout<<"Day??"<<endl;
			return false;
		}
		int hour;
		if(!epLua.GetInt("Hour", &hour))
		{
			cout<<"Hour??"<<endl;
			return false;
		}
		int minute;
		if(!epLua.GetInt("Minute", &minute))
		{
			cout<<"Minute??"<<endl;
			return false;
		}
		SYSTEMTIME localTime =
		{	
			year, month, 0, day, hour, minute, 0, 0	
		};
		//ȡ��ʱ����Ϣ
		TIME_ZONE_INFORMATION tzi;
		GetTimeZoneInformation(&tzi);
		//�ɱ���ʱ��ת����ϵͳʱ��
		SYSTEMTIME sysTime;
		TzSpecificLocalTimeToSystemTime(&tzi, &localTime, &sysTime);
		//��ϵͳʱ��ת�����ļ�ʱ��
		FILETIME fileTime;
		SystemTimeToFileTime(&sysTime, &fileTime);
		//���ļ�ʱ��ת����LARGE_INTEGER
		liDueTime.LowPart = fileTime.dwLowDateTime;
		liDueTime.HighPart = fileTime.dwHighDateTime;
	}
	else
	{
		int seconds;
		if(!epLua.GetInt("Seconds", &seconds))
		{
			cout<<"Seconds??"<<endl;
			return false;
		}
		//second -> 100nanosecond
		liDueTime.QuadPart = -(seconds*1000*1000*10);
	}

	return true;
}

bool LoadSleepTime()
{
	if(!epLua.GetBool("AutoSleep", &bAutoSleep))
	{
		bAutoSleep = false;
	}
	if(!bAutoSleep) return false;
	
	if(!epLua.GetInt("SleepAction", &iSleepAction))
	{
		cout<<"SleepAction??"<<endl;
		return false;
	}
	if(!epLua.GetBool("SUseAbsolute", &bSUseAbsolute))
	{
		cout<<"SUseAbsolute??"<<endl;
		return false;
	}
	if(bSUseAbsolute)
	{
		int year;
		if(!epLua.GetInt("SYear", &year))
		{
			cout<<"SYear??"<<endl;
			return false;
		}
		int month;
		if(!epLua.GetInt("SMonth", &month))
		{
			cout<<"SMonth??"<<endl;
			return false;
		}
		int day;
		if(!epLua.GetInt("SDay", &day))
		{
			cout<<"SDay??"<<endl;
			return false;
		}
		int hour;
		if(!epLua.GetInt("SHour", &hour))
		{
			cout<<"SHour??"<<endl;
			return false;
		}
		int minute;
		if(!epLua.GetInt("SMinute", &minute))
		{
			cout<<"SMinute??"<<endl;
			return false;
		}
		SYSTEMTIME localTime =
		{	
			year, month, 0, day, hour, minute, 0, 0	
		};
		//ȡ��ʱ����Ϣ
		TIME_ZONE_INFORMATION tzi;
		GetTimeZoneInformation(&tzi);
		//�ɱ���ʱ��ת����ϵͳʱ��
		SYSTEMTIME sysTime;
		TzSpecificLocalTimeToSystemTime(&tzi, &localTime, &sysTime);
		//��ϵͳʱ��ת�����ļ�ʱ��
		FILETIME fileTime;
		SystemTimeToFileTime(&sysTime, &fileTime);
		//���ļ�ʱ��ת����LARGE_INTEGER
		liSDueTime.LowPart = fileTime.dwLowDateTime;
		liSDueTime.HighPart = fileTime.dwHighDateTime;
	}
	else
	{
		int seconds;
		if(!epLua.GetInt("SSeconds", &seconds))
		{
			cout<<"SSeconds??"<<endl;
			return false;
		}
		//second -> 100nanosecond
		liSDueTime.QuadPart = -(seconds*1000*1000*10);
	}
	return true;
}

void ExecuteCommands()
{
	for(int i = 0; i < iComNum; ++i)
	{
		cout<<szCommands[i]<<endl;
		WinExec(szCommands[i], SW_SHOW);
	}
}

int main(int argn, const char **args)
{
	if(argn < 2) return 0;
	//��������
	if(!LoadConfig(args[1]))
	{
		return 0;
	}
	//������ʱ��
	HANDLE hTimer = CreateWaitableTimer(NULL, true, "AutoWakeUp");
	cout<<"��ʱ���Ѵ���..."<<endl;
	SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, true);
	if (WaitForSingleObject(hTimer, INFINITE) != WAIT_OBJECT_0)
        cout<<"WaitForSingleObject failed "<<GetLastError()<<endl;
    else
	{
		//hold on system
		SetThreadExecutionState(ES_CONTINUOUS|ES_SYSTEM_REQUIRED);
		ExecuteCommands();
		//�ͷŴ��������ʹ�õ��ڴ�
		for(int i = 0; i < iComNum; ++i)
		{
			delete[] szCommands[i];
			szCommands[i] = 0;
		}
		if(bAutoSleep)	//ʹ���Զ�˯��
		{
			HANDLE hSleepTimer = CreateWaitableTimer(NULL, true, "AutoSleep");
			cout<<"˯�߶�ʱ���Ѵ���..."<<endl;
			SetWaitableTimer(hSleepTimer, &liSDueTime, 0, NULL, NULL, false);
			if (WaitForSingleObject(hSleepTimer, INFINITE) != WAIT_OBJECT_0)
				cout<<"WaitForSingleObject failed "<<GetLastError()<<endl;
			else
			{
				if(iSleepAction == 1)	//Sleep
				{
					SetSuspendState(false, false, true);
				}
				else if(iSleepAction == 2)	//Hibernate
				{
					SetSuspendState(true, false, true);
				}
			}
		}
		system("pause");
		SetThreadExecutionState(ES_CONTINUOUS);
	}
	return 0;
}
