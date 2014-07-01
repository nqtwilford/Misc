#pragma once
#include <memory>
#include "../my_shared_ptr.h"

class A;

class B
{
public:
	B(sptr<A> a);
	~B();

private:
	sptr<A> _a;
};
