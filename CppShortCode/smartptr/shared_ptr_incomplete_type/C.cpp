#include "C.h"
#include "B.h"
#include "../my_shared_ptr.h"


B *C::CreateB(sptr<A> a)
{
	return new B(a);
}
