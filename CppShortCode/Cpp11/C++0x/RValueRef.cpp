#include <string>
#include <iostream>
using namespace std;

string modifiable_rvalue() {

    return "cute";

}

const string const_rvalue() {

    return "fluffy";

}

int main() {
	//string &&str = modifiable_rvalue();
	////str = "modify";
	//cout<<str<<endl;
	//system("pause");
	//return 0;

    string modifiable_lvalue("kittens");

    const string const_lvalue("hungry hungry zombies");

    string& a = modifiable_lvalue;          // 

    //string& b = const_lvalue;               //  - const ERROR

    //string& c = modifiable_rvalue();        //  - 非常量引用只能绑定到左值

    //string& d = const_rvalue();             //  - const ERROR

    const string& e = modifiable_lvalue;    // 

    const string& f = const_lvalue;         // 

    const string& g = modifiable_rvalue();  // 

    const string& h = const_rvalue();       // 

    //string&& i = modifiable_lvalue;         //  无法将左值绑定到右值引用

    //string&& j = const_lvalue;              //  - const ERROR

    string&& k = modifiable_rvalue();       // 

    //string&& l = const_rvalue();            //  -const ERROR

    //const string&& m = modifiable_lvalue;   // 无法将左值绑定到右值引用

    //const string&& n = const_lvalue;        // 无法将左值绑定到右值引用

    const string&& o = modifiable_rvalue(); // 

    const string&& p = const_rvalue();      // 

#pragma warning(disable:4189)
}
