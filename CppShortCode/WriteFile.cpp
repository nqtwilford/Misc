#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **arg)
{
    char *string = new char[512];
    
    ofstream file;
    file.open("output.txt");
//    string = "this is the first line";
//    file.write(string, strlen(string));
	while(fgets(string, 512, stdin) != NULL)
	{
		file.write(string, strlen(string));
	}
    file.close();
    system("pause");
    return 0;
}
