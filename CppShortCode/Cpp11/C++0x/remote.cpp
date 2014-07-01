#include <stddef.h>

#include <iostream>

#include <ostream>

using namespace std;

#define MOVABLE

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

        if (other.m_p) {

            m_p = new int(*other.m_p);

        } else {

            m_p = NULL;

        }

    }

#ifdef MOVABLE

    remote_integer(remote_integer&& other) {

        cout << "MOVE CONSTRUCTOR." << endl;

 

        m_p = other.m_p;

        other.m_p = NULL;

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

remote_integer square(const remote_integer& r) {

    const int i = r.get();

		remote_integer temp(i * i);	//Try to add static

    return temp;

}

int main() {

    remote_integer a(8);

    cout << a.get() << endl;

    remote_integer b(10);

    cout << b.get() << endl;

    b = square(a);

    cout << b.get() << endl;

}
