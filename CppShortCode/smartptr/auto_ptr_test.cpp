#include <memory>

using namespace std;

class Base
{
public:
	virtual ~Base(){}
};

class Derived : public Base
{
};

void AcceptBase(const auto_ptr<Base> ){}

int main()
{
	auto_ptr<Derived> pDerived(new Derived);
//	const auto_ptr<Base> &pBase = pDerived;
	AcceptBase(pDerived);
}