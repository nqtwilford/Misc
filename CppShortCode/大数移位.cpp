#include <iostream>
using namespace std;

unsigned int storage[4] = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
void ShiftLeft(int count)
{
	unsigned int temp = 0;
	for(int i = 0; i < 4; ++i)
	{
		storage[i] = storage[i] << count | temp;
		temp = storage[i] >> sizeof(unsigned int)*8 - count;
	}
}
bool ShiftRight(int count)
{
	unsigned int temp = 0;
	for(int i = 3; i >= 0; --i)
	{
		storage[i] = storage[i] >> count | temp;
		temp = storage[i] << sizeof(unsigned int)*8 - count;
	}
}

int main(int argc, char **argv)
{
	ShiftRight(3);
	for(int i = 3; i >= 0; --i)
	{
		cout<<hex<<storage[i]<<" ";
	}
	cout<<endl;
	return EXIT_SUCCESS;
}
