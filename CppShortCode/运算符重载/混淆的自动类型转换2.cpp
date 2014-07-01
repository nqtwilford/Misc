class A{};
class B{};

class C
{
public:
	operator A();
	operator B();
};

void f(A);
void f(B);

int main()
{
	C c;
//	f(c);	//call of overloaded `f(C&)' is ambiguous
	//you can:
	f(c.operator A());
	//or:
	f(c.operator B());
}
