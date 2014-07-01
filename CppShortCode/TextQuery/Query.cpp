#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "NotQuery.h"

Query operator&(const Query &lhs, const Query &rhs)
{
	return new AndQuery(lhs, rhs);
}
Query operator|(const Query &lhs, const Query &rhs)
{
	return new OrQuery(lhs, rhs);
}
Query operator~(const Query &oper)
{
	return new NotQuery(oper);
}
std::ostream &operator <<(std::ostream &os, const Query &q)
{
	return q.display(os);
}