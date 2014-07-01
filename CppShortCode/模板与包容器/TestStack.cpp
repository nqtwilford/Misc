#include "Stack.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	Stack<float> st;
	st.Push(1.1f);
	st.Push(2.2f);
	st.Push(3.3f);
	st.Push(4.4f);
	st.Push(5.5f);
	if(!st.Push(6.6f))
	{
		cout<<"插不进去了"<<endl;
	}
	float f;
	while(st.Pop(&f))
	{
		cout<<f<<endl;
	}
	return 0;
}
