#include <windows.h> 
 
int WINAPI WinMain (HINSTANCE hInstance,  
                    HINSTANCE hPrevInstance,  
                    PSTR szCmdLine,  
                    int iCmdShow)  
{ 
	MessageBox (NULL, "Hello World, My Dear", "Hello Demo", MB_OK); 
	return (0);
}
