#include <iostream>

#include <ostream>

using namespace std;

template <typename T> struct Identity {

    typedef T type;

};

//template <typename T> T&& Forward(typename Identity<T>::type&& t) {
//
//    return t;
//
//}

void inner(int&, int&) {

    cout << "inner(int&, int&)" << endl;

}

void inner(int&, const int&) {

    cout << "inner(int&, const int&)" << endl;

}

void inner(const int&, int&) {

    cout << "inner(const int&, int&)" << endl;

}

void inner(const int&, const int&) {

    cout << "inner(const int&, const int&)" << endl;

}

template <typename T1, typename T2> void outer(T1&& t1, T2&& t2) {

    inner(forward<T1>(t1), forward<T2>(t2));

}

int main() {

    int a = 1;

    const int b = 2;

    cout << "Directly calling inner()." << endl;

    inner(a, a);

    inner(b, b);

    inner(3, 3);

    inner(a, b);

    inner(b, a);

    inner(a, 3);

    inner(3, a);

    inner(b, 3);

    inner(3, b);

    cout << endl << "Calling outer()." << endl;

    outer(a, a);

    outer(b, b);

    outer(3, 3);

    outer(a, b);

    outer(b, a);

    outer(a, 3);

    outer(3, a);

    outer(b, 3);

    outer(3, b);

}
