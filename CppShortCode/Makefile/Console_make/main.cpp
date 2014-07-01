#include <iostream> 
using namespace std; 
 
int main(int argc, char* argv[]) 
{ 
	cout << "hello world"<<endl;     
	
	cout << "----------------------------" << endl; 
	cout << "filename=" << __FILE__ << " line="<< __LINE__ << endl; 
	cout << "time="<< __TIME__ << " date="<< __DATE__ << endl; 
	cout << "funname="<< __func__ << endl; 
	cout << "----------------------------" << endl; 
	
	return 0;
}
