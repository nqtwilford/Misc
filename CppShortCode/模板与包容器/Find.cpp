#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(int argc, char **argv)
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);
	vector<int>::const_iterator iter =
		find(vec.begin(), vec.end(), 5);
	//查找失败时，find返回第二个实参，而并不一定是end
	if(iter != vec.end())
		cout<<"Found"<<endl;
	else
		cout<<"Not Found"<<endl;

	list<int> lst;
	lst.push_back(1);
	lst.push_back(3);
	lst.push_back(2);
	lst.push_back(4);
	list<int>::const_iterator iter1 =
		find(lst.begin(), lst.end(), 3);
	//查找失败时，find返回第二个实参，而并不一定是end
	if(iter1 != lst.end())
		cout<<"Found"<<endl;
	else
		cout<<"Not Found"<<endl;

	int ia[6] = {27, 210, 12, 47, 109, 83};
	int search_value = 83;
	int *result = find(ia, ia + 6, search_value);
	cout << "The value " << search_value
			<< (result == ia + 6
						? " is not present" : " is present")
			<< endl;

	return EXIT_SUCCESS;
}
