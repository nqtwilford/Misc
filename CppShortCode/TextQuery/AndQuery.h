#ifndef _ANDQUERY_H_
#define _ANDQUERY_H_

#include "BinaryQuery.h"

class AndQuery: public BinaryQuery 
{
    friend Query operator&(const Query&, const Query&);
private:
    AndQuery (Query left, Query right): BinaryQuery(left, right, "&") { }
    // concrete class: And Query inherits display and defines remaining pure virtual
    std::set<line_no> eval(const TextQuery&) const;
};

#endif
