#include <iostream>
#include <vector>
#include <list>
#include <numeric>
using namespace std;

int main(int argc, char **argv)
{
	//整数求和
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	int sum = accumulate(vec.begin(), vec.end(), 2);
	cout<<sum<<endl;
	//字符串连接
	vector<string> lst;
	lst.push_back("Hello");
	lst.push_back("World");
	lst.push_back("!");
	string str = accumulate(lst.begin(), lst.end(), string("Prefix"));
	cout<<str<<endl;

	//一个错误的计算
	vector<double> vec1;
	vec1.push_back(0.1);
	vec1.push_back(0.2);
	vec1.push_back(0.3);
	//不会出错，但是有警告。累计时自动将double转换为int，累计结果不正确
	double sum1 = accumulate(vec1.begin(), vec1.end(), 0);
	cout<<sum1<<endl;

	return EXIT_SUCCESS;
}
