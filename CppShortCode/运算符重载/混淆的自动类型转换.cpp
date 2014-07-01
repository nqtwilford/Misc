class X;
class Y;

class X
{
public:
	X(Y);	//由Y构造X
};

class Y
{
public:
	operator X();	//将自身转换到X
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
