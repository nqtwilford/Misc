#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;
#include <windows.h>
int main(int argc, char **argv)
{
	//���뵥�ʷ����
	typedef map<string, string> WordsMap;
	WordsMap wordsMap;
	ifstream words("WordsMap.txt");
	if(!words) return -1;
	string key, value;
	while(words>>key>>value)
		wordsMap[key] = value;
	//������������
	ifstream sentence("Sentence.txt");
	if(!sentence) return -1;
	string word;
	while(getline(sentence, word))
	{
		istringstream str(word);
		while(str>>word)
		{
			WordsMap::const_iterator iter = wordsMap.find(word);
			if(iter != wordsMap.end())
			{
				cout<<iter->second<<" ";
			}
			else
			{
				cout<<word<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
