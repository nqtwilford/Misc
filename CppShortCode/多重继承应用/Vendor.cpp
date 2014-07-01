#include <fstream>
#include "Vendor.h"
using namespace std;

extern ofstream out;

void Vendor::v() const
{
	out<<"Vendor::v()\n";
}

void Vendor::f() const
{
	out<<"Vendor::f()\n";
}

Vendor::~Vendor()
{
	out<<"~Vendor()\n";
}

void Vendor1::v() const
{
	out<<"Vendor1::v()\n";
}

void Vendor1::f() const
{
	out<<"Vendor1::f()\n";
}

Vendor1::~Vendor1()
{
	out<<"~Vendor1()\n";
}

void A(const Vendor &ven)
{
	ven.v();
	ven.f();
}

void B(const Vendor &ven)
{
	ven.v();
	ven.f();
}
