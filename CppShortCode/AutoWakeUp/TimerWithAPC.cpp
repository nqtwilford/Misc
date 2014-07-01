#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#define _SECOND 10000000

typedef struct _MYDATA {
   TCHAR *szText;
   DWORD dwValue;
} MYDATA;

int seconds = 0;

VOID CALLBACK TimerAPCProc(
   LPVOID lpArg,               // Data value
   DWORD dwTimerLowValue,      // Timer low value
   DWORD dwTimerHighValue )    // Timer high value

{
//   MYDATA *pMyData = (MYDATA *)lpArg;
//
//   _tprintf( TEXT("Message: %s\nValue: %d\n\n"), pMyData->szText,
//          pMyData->dwValue );
	printf("I'm coming %i\n", seconds++);
//   MessageBeep(MB_OK);
Beep( 750, 300 );


}

int main( void ) 
{
   HANDLE          hTimer;
   BOOL            bSuccess;
   __int64         qwDueTime;
   LARGE_INTEGER   liDueTime;
   MYDATA          MyData;

   MyData.szText = TEXT("This is my data");
   MyData.dwValue = 100;

   hTimer = CreateWaitableTimer(
           NULL,                   // Default security attributes
           FALSE,                  // Create auto-reset timer
           TEXT("MyTimer"));       // Name of waitable timer
   if (hTimer != NULL)
   {
		// Create an integer that will be used to signal the timer 
		// 5 seconds from now.
		qwDueTime = -1 * _SECOND;

		// Copy the relative time into a LARGE_INTEGER.
		liDueTime.LowPart  = (DWORD) ( qwDueTime & 0xFFFFFFFF );
		liDueTime.HighPart = (LONG)  ( qwDueTime >> 32 );

		bSuccess = SetWaitableTimer(
			hTimer,           // Handle to the timer object
			&liDueTime,       // When timer will become signaled
			1000,             // Periodic timer interval of 2 seconds
			TimerAPCProc,     // Completion routine
			NULL,          // Argument to the completion routine
			TRUE );          // Do not restore a suspended system

		if ( bSuccess ) 
		{
			for ( ;; ) 
			{
//				SleepEx(INFINITE,     // Wait forever
//						TRUE );       // Put thread in an alertable state
				printf("fsdf\n");
				SleepEx(1000, TRUE);
			}

		} 
		else 
		{
			printf("SetWaitableTimer failed with error %d\n",
				GetLastError());
		}
		CloseHandle( hTimer );
   } 
   else 
   {
      printf("CreateWaitableTimer failed with error %d\n",
         GetLastError());
   }
}
