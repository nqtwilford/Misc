#ifndef _BINARYQUERY_H_
#define _BINARYQUERY_H_

#include "QueryBase.h"
#include "Query.h"

class BinaryQuery: public QueryBase
{
protected:
    BinaryQuery(Query left, Query right, std::string op):
          lhs(left), rhs(right), oper(op) { }
    // abstract class: BinaryQuery doesn't define eval
    std::ostream& display(std::ostream &os) const
    { return os << "(" << lhs << " " << oper << " " << rhs << ")"; }

    const Query lhs, rhs; // right- and left-hand operands
    const std::string oper; // name of the operator
};

#endif
