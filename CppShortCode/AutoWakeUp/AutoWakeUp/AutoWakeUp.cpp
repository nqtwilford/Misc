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
bool bAutoSleep;		//是否自动睡眠
int  iSleepAction;		//1:Sleep 2:Hibernate
bool bSUseAbsolute;		//睡眠定时是否使用绝对时间
LARGE_INTEGER liSDueTime;	//睡眠的定时时间

bool LoadConfig(const char *fileName);
bool LoadWakeUpTime();
bool LoadSleepTime();
void ExecuteCommands();

bool LoadConfig(const char *fileName)
{
	if(!epLua.LoadScript(fileName))
	{
		cout<<"加载配置文件:"<<fileName<<"失败"<<endl;
		return false;
	}
	//读取唤醒时间
	if(!LoadWakeUpTime())
	{
		return false;
	}
	//读取需要执行的命令，lua中数组下标从1开始
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
	//读取睡眠时间
	bAutoSleep = LoadSleepTime();
	if(bAutoSleep)
		cout<<"启用自动睡眠"<<endl;
	else
		cout<<"不启用自动睡眠"<<endl;
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
		//取得时区信息
		TIME_ZONE_INFORMATION tzi;
		GetTimeZoneInformation(&tzi);
		//由本地时间转换到系统时间
		SYSTEMTIME sysTime;
		TzSpecificLocalTimeToSystemTime(&tzi, &localTime, &sysTime);
		//由系统时间转换到文件时间
		FILETIME fileTime;
		SystemTimeToFileTime(&sysTime, &fileTime);
		//由文件时间转换到LARGE_INTEGER
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
		//取得时区信息
		TIME_ZONE_INFORMATION tzi;
		GetTimeZoneInformation(&tzi);
		//由本地时间转换到系统时间
		SYSTEMTIME sysTime;
		TzSpecificLocalTimeToSystemTime(&tzi, &localTime, &sysTime);
		//由系统时间转换到文件时间
		FILETIME fileTime;
		SystemTimeToFileTime(&sysTime, &fileTime);
		//由文件时间转换到LARGE_INTEGER
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
	//加载配置
	if(!LoadConfig(args[1]))
	{
		return 0;
	}
	//创建定时器
	HANDLE hTimer = CreateWaitableTimer(NULL, true, "AutoWakeUp");
	cout<<"定时器已创建..."<<endl;
	SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, true);
	if (WaitForSingleObject(hTimer, INFINITE) != WAIT_OBJECT_0)
        cout<<"WaitForSingleObject failed "<<GetLastError()<<endl;
    else
	{
		//hold on system
		SetThreadExecutionState(ES_CONTINUOUS|ES_SYSTEM_REQUIRED);
		ExecuteCommands();
		//释放存放命令所使用的内存
		for(int i = 0; i < iComNum; ++i)
		{
			delete[] szCommands[i];
			szCommands[i] = 0;
		}
		if(bAutoSleep)	//使用自动睡眠
		{
			HANDLE hSleepTimer = CreateWaitableTimer(NULL, true, "AutoSleep");
			cout<<"睡眠定时器已创建..."<<endl;
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
