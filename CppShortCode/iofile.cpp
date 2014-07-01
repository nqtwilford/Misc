#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in1("iofile.cpp");
	ofstream out1("iofile.out");
	out1<<in1.rdbuf();
	in1.close();
	out1.close();

	ifstream in2("iofile.out", ios::in|ios::out);
	ostream out2(in2.rdbuf());
	cout<<in2.rdbuf();
	out2<<"Where does this end up"<<endl;
	out2.seekp(0, ios::beg);
	out2<<"this is?";
	in2.seekg(0, ios::beg);
	cout<<in2.rdbuf();
}
