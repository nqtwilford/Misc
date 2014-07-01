#include <iostream>
#include <vector>
#include <list>
#include <numeric>
using namespace std;

int main(int argc, char **argv)
{
	//�������
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	int sum = accumulate(vec.begin(), vec.end(), 2);
	cout<<sum<<endl;
	//�ַ�������
	vector<string> lst;
	lst.push_back("Hello");
	lst.push_back("World");
	lst.push_back("!");
	string str = accumulate(lst.begin(), lst.end(), string("Prefix"));
	cout<<str<<endl;

	//һ������ļ���
	vector<double> vec1;
	vec1.push_back(0.1);
	vec1.push_back(0.2);
	vec1.push_back(0.3);
	//������������о��档�ۼ�ʱ�Զ���doubleת��Ϊint���ۼƽ������ȷ
	double sum1 = accumulate(vec1.begin(), vec1.end(), 0);
	cout<<sum1<<endl;

	return EXIT_SUCCESS;
}
