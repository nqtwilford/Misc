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

    //string& c = modifiable_rvalue();        //  - �ǳ�������ֻ�ܰ󶨵���ֵ

    //string& d = const_rvalue();             //  - const ERROR

    const string& e = modifiable_lvalue;    // 

    const string& f = const_lvalue;         // 

    const string& g = modifiable_rvalue();  // 

    const string& h = const_rvalue();       // 

    //string&& i = modifiable_lvalue;         //  �޷�����ֵ�󶨵���ֵ����

    //string&& j = const_lvalue;              //  - const ERROR

    string&& k = modifiable_rvalue();       // 

    //string&& l = const_rvalue();            //  -const ERROR

    //const string&& m = modifiable_lvalue;   // �޷�����ֵ�󶨵���ֵ����

    //const string&& n = const_lvalue;        // �޷�����ֵ�󶨵���ֵ����

    const string&& o = modifiable_rvalue(); // 

    const string&& p = const_rvalue();      // 

#pragma warning(disable:4189)
}
