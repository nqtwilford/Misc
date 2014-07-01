#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	cout<<"function:"<<sizeof(function<void()>)<<endl;
	cout<<"string:"<<sizeof(string)<<endl;
	cout<<"vector:"<<sizeof(vector<int>)<<endl;
	cout<<"map:"<<sizeof(map<int, int>)<<endl;
	return 0;
}
