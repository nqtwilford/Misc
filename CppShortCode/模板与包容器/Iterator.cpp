#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	vector<int> vec;
//	vector<int>::iterator iterEnd = vec.end();
//	*iterEnd = 1;	//Crash
	vec.push_back(1);
//	vector<int>::const_iterator iter = vec.begin();
//	*iter = 2;	//compile error
	vec.push_back(2);
//	const vector<int>::iterator iter = vec.begin();
//	++iter;		//compile error
	vec.push_back(3);
	vec.push_back(4);
//	vector<int>::iterator iter = (vec.begin()+vec.end())/2;	//compile error
	vector<int>::iterator iter = vec.begin() + vec.size() / 2;
	cout<<(*iter)<<endl;
	return 0;
}
