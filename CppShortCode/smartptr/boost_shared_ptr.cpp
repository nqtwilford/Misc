#include "boost\shared_ptr.hpp"
#include "t.h"

int main()
{
	boost::shared_ptr<Base> t(new Base(10));
	return 0;
}
