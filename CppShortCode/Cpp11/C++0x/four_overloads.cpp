#include <iostream>
#include <ostream>
#include <string>

using namespace std;

void meow(string& s) {

    cout << "meow(string&): " << s << endl;

}

void meow(const string& s) {

    cout << "meow(const string&): " << s << endl;

}

void meow(string&& s) {

    cout << "meow(string&&): " << s << endl;

}

void meow(const string&& s) {

    cout << "meow(const string&&): " << s << endl;

}

string strange() {

    return "strange()";

}

const string charm() {

    return "charm()";

}

int main() {

    string up("up");

    const string down("down");

    meow(up);

    meow(down);

    meow(strange());

    meow(charm());

}
