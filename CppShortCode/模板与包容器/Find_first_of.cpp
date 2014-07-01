//查找names1和names2中共有的元素
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
using namespace std;

int main(int argc, char **argv)
{
	vector<string> names1;
	names1.push_back("zhang");
	names1.push_back("wilford");
	names1.push_back("wei");

	list<string> names2;
	names2.push_back("zhang");
	names2.push_back("wei");

	vector<string>::iterator iter = names1.begin();
	while(true)
	{
		iter = find_first_of(iter, names1.end(), names2.begin(), names2.end());
		if(iter != names1.end())
			cout<<*iter<<endl;
		else
			break;
		++iter;
	}

	string str1 = "zhangwei";
	string str2 = "weg";
	for(string::iterator iter = str1.begin();
		iter != str1.end(); ++iter)
	{
		iter = find_first_of(iter, str1.end(), str2.begin(), str2.end());
		if(iter != str1.end())
		{
			cout<<*iter<<endl;
		}
		else
		{
			--iter;
		}
	}
	
	return EXIT_SUCCESS;
}
