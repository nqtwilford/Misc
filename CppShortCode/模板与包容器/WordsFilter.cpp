#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

template <class T>
void print(T val)
{
	cout<<val<<endl;
}

// comparison function to be used to sort by word length
bool isShorter(const string &s1, const string &s2)
{
	 return s1.size() < s2.size();
}

// determine whether a length of a given word is 6 or more
template <int SIZE>
bool ShorterThan(const string &s)
{
		return s.size() < SIZE;
}

int main(int argc, char **argv)
{
	//����������
	istringstream is("the quick red fox jumps over the slow red turtle");
	//����װ��vector
	vector<string> words;
	back_insert_iterator<vector<string> > iter = back_inserter(words);
	string word;
	while(is>>word)
		*iter = word;
	//���е�������
	sort(words.begin(), words.end());
	//ɾ���ظ���unique��Ԫ���������򣬰��ظ�Ԫ���Ƶ���󣬷��ص�����ָʾ���ظ��Ľ���λ��
	vector<string>::iterator del_iter = unique(words.begin(), words.end());
	words.erase(del_iter, words.end());
	//�����ʳ������򣬶��ڳ�����ȵĵ��ʣ������ֵ������ʹ��stable_sort
	//stable_sort��sort��֮ͬ�����ڣ�stable_sort�������Ԫ�ص����λ��
	stable_sort(words.begin(), words.end(), isShorter);
//	//���㳤��С��5�ĵ��ʵĸ���
//	vector<string>::size_type count = count_if(words.begin(), words.end(), ShorterThan<5>);
//	//ɾ������С��5�ĵ���
//	words.erase(words.begin(), words.begin() + count);
	//�ڶ���ɾ������С��5�ĵ��ʵķ���
	vector<string>::iterator del_iter1;
	while((del_iter1 = find_if(words.begin(), words.end(), ShorterThan<5>)) != words.end())
		words.erase(del_iter1);
	for_each(words.begin(), words.end(), print<vector<string>::value_type>);

	return 0;
}
