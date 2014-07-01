#include "C.h"

C::C(int i):m_i(i){}

const int &C::Geti()
{
	return m_i;
}
