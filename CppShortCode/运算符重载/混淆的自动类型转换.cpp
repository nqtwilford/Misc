class X;
class Y;

class X
{
public:
	X(Y);	//��Y����X
};

class Y
{
public:
	operator X();	//������ת����X
};

void f(X);

int main()
{
	Y y;
//	f(y);		//conversion from 'Y' to 'X' is ambiguous
	//you can:
	f(y.operator X());
	//or:
	f(X(y));
}
