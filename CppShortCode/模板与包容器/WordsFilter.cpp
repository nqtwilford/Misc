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
	//构造输入流
	istringstream is("the quick red fox jumps over the slow red turtle");
	//单词装入vector
	vector<string> words;
	back_insert_iterator<vector<string> > iter = back_inserter(words);
	string word;
	while(is>>word)
		*iter = word;
	//所有单词排序
	sort(words.begin(), words.end());
	//删除重复，unique将元素重新排序，把重复元素移到最后，返回迭代器指示无重复的结束位置
	vector<string>::iterator del_iter = unique(words.begin(), words.end());
	words.erase(del_iter, words.end());
	//按单词长度排序，对于长度相等的单词，保留字典序，因此使用stable_sort
	//stable_sort与sort不同之处在于，stable_sort保留相等元素的相对位置
	stable_sort(words.begin(), words.end(), isShorter);
//	//计算长度小于5的单词的个数
//	vector<string>::size_type count = count_if(words.begin(), words.end(), ShorterThan<5>);
//	//删除长度小于5的单词
//	words.erase(words.begin(), words.begin() + count);
	//第二种删除长度小于5的单词的方法
	vector<string>::iterator del_iter1;
	while((del_iter1 = find_if(words.begin(), words.end(), ShorterThan<5>)) != words.end())
		words.erase(del_iter1);
	for_each(words.begin(), words.end(), print<vector<string>::value_type>);

	return 0;
}
