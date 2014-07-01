#include "keys.h"
#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include <windows.h>

using namespace std;

template <typename set_type>
void insertkeys(set_type &setobj)
{
	for(size_t i = 0; i < sizeof(keys)/sizeof(keys[1]); ++i)
	{
		setobj.insert(keys[i]);
	}
}

template <typename set_type>
void searchkeys(set_type &setobj)
{
	for(size_t i = 0; i < sizeof(keys)/sizeof(keys[1]); ++i)
	{
		setobj.find(keys[i]);
	}
}

int main()
{
	//insert time
	DWORD t0 = timeGetTime();
	set<string> keyset;
	insertkeys(keyset);
	DWORD t1 = timeGetTime();
	unordered_set<string> keyset1;
	insertkeys(keyset1);
	DWORD t2 = timeGetTime();
	cout<<(t1-t0)<<" "<<(t2-t1)<<endl;

	//search time
	DWORD t3 = timeGetTime();
	searchkeys(keyset);
	DWORD t4 = timeGetTime();
	searchkeys(keyset1);
	DWORD t5 = timeGetTime();
	cout<<(t4-t3)<<" "<<(t5-t4)<<endl;
	
}	
