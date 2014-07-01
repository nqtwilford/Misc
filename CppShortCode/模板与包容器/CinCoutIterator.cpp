#include <iostream>
#include <iterator>
using namespace std;

int main(int argc, char **argv)
{
	ostream_iterator<string> os_iter(cout, ",\n");
	istream_iterator<string> is_iter(cin), eof;
	do
	{
		*os_iter = *is_iter;
	}
	while (++os_iter, ++is_iter != eof);
	return 0;
}
