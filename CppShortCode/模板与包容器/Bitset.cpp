#include <iostream>
#include <bitset>
using namespace std;

int main(int argc, char *argv[])
{
	bitset<16> bset1(0xf0f0);
	cout<<bset1<<endl;
	string str("1111111000000011001101");
	bitset<32> bitvec5(str, 5, 4); // 4 bits starting at str[5], 1100
	bitset<32> bitvec6(str, str.size() - 4);     // use last 4 characters
	cout<<bitvec5<<endl;
	cout<<bitvec6<<endl;
	cout<<sizeof(bitvec5)<<endl;
	cout<<bitvec6.count()<<endl;
	cout<<typeid(bitvec5[3]).name()<<endl;
	bitvec5 |= 0xf;	//last 4 bits sets to on 
	cout<<bitvec5<<endl;

	return 0;
}
