#include "A.h"
#include "B.h"
#include "C.h"
#include <memory>
#include "../my_shared_ptr.h"

class D;

int main()
{
	sptr<A> a(new A);
	std::unique_ptr<B> b(C::CreateB(a));
	//sptr<D> d((D *)new int(1));
}
