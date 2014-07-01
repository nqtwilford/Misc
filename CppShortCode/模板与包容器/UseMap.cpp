#include <iostream>
#include <map>
using namespace std;

typedef map<string, int> SIMap;

void print(const SIMap::value_type &pr)
{
	cout<<pr.first<<":"<<pr.second<<endl;
}

int main(int argc, char *argv[])
{
	SIMap simap;
	simap["Zero"] = 0;
	simap["One"] = 1;
	simap["ONE"] = 1;
	simap["Three"] = 3;
	simap["Two"] = 2;
	simap["Four"] = 4;
	//print all values
	for_each(simap.begin(), simap.end(), print);	//map中是按照key排序的
	cout<<endl;
	//or
	for(SIMap::const_iterator iter = simap.begin();
		iter != simap.end(); ++iter)
	{
		cout<<iter->first<<":"<<iter->second<<endl;
	}
	//Let's do a word count
	simap.clear();
	cout<<"Let's do a word count, enter words:"<<endl;
	string word;
	while(cin>>word)
		++simap[word];
	for_each(simap.begin(), simap.end(), print);
	cout<<endl;
	
	cout<<"Let's do another word count, enter words:"<<endl;
	simap.clear();
	cin.clear();
	while(cin>>word)
		++(simap.insert(make_pair(word, 0)).first->second);
	for_each(simap.begin(), simap.end(), print);
	cout<<endl;
	SIMap::const_iterator iter = simap.find("wilford");
	if(iter != simap.end())
		cout<<"wilford出现次数:"<<iter->second<<endl;
	else
		cout<<"未出现wilford"<<endl;
	return 0;
}
