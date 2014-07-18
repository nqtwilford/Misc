#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <memory>

using namespace std;

int main()
{
	cout<<"function:"<<sizeof(function<void()>)<<endl;
	cout<<"string:"<<sizeof(string)<<endl;
	cout<<"vector:"<<sizeof(vector<int>)<<endl;
	cout<<"map:"<<sizeof(map<int, int>)<<endl;
	cout<<"shared_ptr:"<<sizeof(shared_ptr<int>)<<endl;
	cout<<"weak_ptr:"<<sizeof(weak_ptr<int>)<<endl;
	return 0;
}
