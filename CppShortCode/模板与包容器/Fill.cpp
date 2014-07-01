//����names1��names2�й��е�Ԫ��
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

template <class T>
void print(T val)
{
	cout<<val<<endl;
}

int main(int argc, char **argv)
{
	vector<double> vec;
	vec.push_back(0.1);
	vec.push_back(0.2);
	vec.push_back(0.3);

	*vec.end() = 10;

	cout<<*vec.end()<<endl;
	//fill��д������Χ��Ԫ�أ������ϵ�������ͬ
	//��mingw�л��޸ĵ������޸ĵ�Ԫ�أ���vc�л����
	fill(vec.begin(), vec.end()+1, 0);
	cout<<*vec.end()<<endl;
	for_each(vec.begin(), vec.end(), print<double>);

	//fill_nҲ��д������Χ��Ԫ��
	*vec.end() = 10;
	fill_n(vec.begin(), 4, 0);
	cout<<*vec.end()<<endl;

//	//����ʹ��back_inserter�󲿲���
	fill_n(back_inserter(vec), 3, 1);
	for_each(vec.begin(), vec.end(), print<vector<double>::value_type>);

	return EXIT_SUCCESS;
}
