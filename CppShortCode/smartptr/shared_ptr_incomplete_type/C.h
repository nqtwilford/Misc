#pragma once
#include <memory>
#include "../my_shared_ptr.h"

class A;
class B;

class C
{
public:
	static B *CreateB(sptr<A> a);
};
