#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	HWND WndHandle   =   FindWindow(L"Progman",NULL);   
	WndHandle   =GetWindow(WndHandle,GW_CHILD); 
	ShowWindow(WndHandle,SW_HIDE);  
	//ShowWindow(WndHandle,SW_SHOW);
	return 0;
}