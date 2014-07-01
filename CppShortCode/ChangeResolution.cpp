#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,PSTR szCmdLine, int iCmdShow)
{
	int x=GetSystemMetrics(SM_CXSCREEN);
	DEVMODE lpDevMode; 
	memset(&lpDevMode,0,sizeof(DEVMODE));  
	if(EnumDisplaySettings(NULL,0,&lpDevMode)) 
	{ 
		lpDevMode.dmFields=DM_PELSWIDTH|DM_PELSHEIGHT|DM_BITSPERPEL|DM_DISPLAYFREQUENCY; 
		if (x==1024)
		{
			lpDevMode.dmPelsWidth=1280; 
			lpDevMode.dmPelsHeight=1024; 
		}
		else
		{
			lpDevMode.dmPelsWidth=1024; 
			lpDevMode.dmPelsHeight=768; 
		}
		lpDevMode.dmBitsPerPel=32;
		lpDevMode.dmDisplayFrequency=70;
		lpDevMode.dmSize=sizeof(DEVMODE);   
		if(!(ChangeDisplaySettings(&lpDevMode,CDS_UPDATEREGISTRY|CDS_RESET|CDS_GLOBAL)==DISP_CHANGE_SUCCESSFUL)) 
		{ 
			MessageBox(NULL,L"分辨率更改没有成功，请手动更改！",L"分辨率更改错误",MB_OK+MB_ICONERROR); 
			return 0; 
		}   
	} 

	return 0;
}