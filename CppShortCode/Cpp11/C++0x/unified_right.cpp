#include <stddef.h>

#include <iostream>

#include <ostream>

using namespace std;

#define MOVABLE

template <typename T> struct RemoveReference {

     typedef T type;

};

template <typename T> struct RemoveReference<T&> {

     typedef T type;

};

template <typename T> struct RemoveReference<T&&> {

     typedef T type;

};

template <typename T> typename RemoveReference<T>::type&& Move(T&& t) {

    return t;		//在VC2010正式版中，已不能工作。无法将左值绑定到右值引用。调用时传入的是左值，见73行

}

class remote_integer {

public:

    remote_integer() {

        cout << "Default constructor." << endl;

        m_p = NULL;

    }

    explicit remote_integer(const int n) {

        cout << "Unary constructor." << endl;

        m_p = new int(n);

    }

    remote_integer(const remote_integer& other) {

        cout << "Copy constructor." << endl;

        m_p = NULL;

        *this = other;

    }

#ifdef MOVABLE

    remote_integer(remote_integer&& other) {

        cout << "MOVE CONSTRUCTOR." << endl;

        m_p = NULL;

//        *this = Move(other); // RIGHT	不能工作
					*this = move(other);	//可使用stl的move

    }

#endif // #ifdef MOVABLE

    remote_integer& operator=(const remote_integer& other) {

        cout << "Copy assignment operator." << endl;

        if (this != &other) {

            delete m_p;

            if (other.m_p) {

                m_p = new int(*other.m_p);

            } else {

                m_p = NULL;

            }

        }

        return *this;

    }

#ifdef MOVABLE

    remote_integer& operator=(remote_integer&& other) {

        cout << "MOVE ASSIGNMENT OPERATOR." << endl;

        if (this != &other) {

            delete m_p;

            m_p = other.m_p;

            other.m_p = NULL;

        }

        return *this;

    }

#endif // #ifdef MOVABLE

    ~remote_integer() {

        cout << "Destructor." << endl;

        delete m_p;

    }

    int get() const {

        return m_p ? *m_p : 0;

    }

private:

    int * m_p;

};

remote_integer frumple(const int n) {

    if (n == 1729) {

        return remote_integer(1729);

    }

    remote_integer ret(n * n);

    return ret;

}

int main() {

    remote_integer x = frumple(5);

    cout << x.get() << endl;

    remote_integer y = frumple(1729);

    cout << y.get() << endl;

}
