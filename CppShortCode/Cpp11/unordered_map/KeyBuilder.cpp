#include <fstream>
#include <string>

using namespace std;

string GetRandomKey()
{
	string str;
	int len = rand()%9 + 1;
	str.resize(len);
	for(int i = 0; i < len; ++i)
	{
		char c = 'a' + rand()%26;
		str[i] = c;
	}
	return str;
}

int main()
{
	ofstream ofs("keys.h");
	ofs<<"const char *keys[]={\n";
	for(int i = 0; i < 100000; ++i)
	{
		ofs<<"\t\""<<GetRandomKey()<<"\",\n";
	}
	ofs<<"};"<<endl;
}	
