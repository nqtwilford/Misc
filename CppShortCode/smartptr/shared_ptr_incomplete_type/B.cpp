#include "B.h"
#include "A.h"
#include <iostream>
#include "../my_shared_ptr.h"

B::B(sptr<A> a)
:_a(a)
{}

B::~B()
{
	std::cout<<"B::~B()"<<std::endl;
}

