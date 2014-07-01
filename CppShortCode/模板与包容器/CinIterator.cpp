#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

template <class T>
void Print(const T &val)
{
	cout<<val<<endl;
}

int main(int argc, char **argv)
{
	cout<<"Enter some integers(end of Ctrl+Z)"<<endl;
	vector<int> vec;
	istream_iterator<int> in_iter(cin); // read ints from cin
	istream_iterator<int> eof; // istream "end" iterator
	// read until end of file, storing what was read in vec
	while (in_iter != eof)
		vec.push_back(*in_iter++);
	for_each(vec.begin(), vec.end(), Print<int>);

	cout<<"Wasn't than fun? Let's try something else."<<endl;
	cout<<"Enter some string(end of Ctrl+Z)"<<endl; 
	cin.clear();
	istream_iterator<string> cin_iter1(cin);
	istream_iterator<string> eof1;
	//vector的拷贝构造函数，两个迭代器指示拷贝范围
	vector<string> vec1(cin_iter1, eof1);	
	for_each(vec1.begin(), vec1.end(), Print<string>);
	return 0;
}
