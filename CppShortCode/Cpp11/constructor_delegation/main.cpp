#include <string>
#include <iostream>

using namespace std;

class SomeType {
  int number;
  string name;
  SomeType( int i, const string& s ) : number(i), name(s){}
public:
  SomeType( )           : SomeType( 0, "invalid" ){ Show(); }
  SomeType( int i )     : SomeType( i, "guest" ){ Show(); }
  SomeType( const string& s ) : SomeType( 1, s ){ Show(); }
  void Show()
  {
	  std::cout<<"number:"<<number<<" name:"<<name<<std::endl;
  }
};

int main()
{
	SomeType obj;
	obj.Show();
	SomeType obj1(10);
	obj1.Show();
	SomeType obj2("hello");
	obj2.Show();
	return 0;
}

