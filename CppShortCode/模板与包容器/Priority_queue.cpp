#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(int argc, char **argv)
{
	priority_queue<int, vector<int>, less<int> > st;
	st.push(1);
	st.push(3);
	st.push(2);
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
	return 0;
}
