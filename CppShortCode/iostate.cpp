#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

int main(int argc, char **argv)
{
	int ival;
	// read cin and test only for EOF; loop is executed even if there are other IO failures
	while (cin >> ival, !cin.eof()) {
			if (cin.bad())         // input stream is corrupted; bail out
					throw runtime_error("IO stream corrupted");
			if (cin.fail()) {                        // bad input
					cerr<< "bad data, try again"<<endl;        // warn the user
//					cin.clear(istream::failbit);         // reset the stream	todo:test in vc
					cin.clear();
					string str;
					cin>>str;
					continue;                            // get next input
			}
			// ok to process ival
	}
	return 0;
}
