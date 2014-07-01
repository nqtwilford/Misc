#ifndef _NOTQUERY_H_
#define _NOTQUERY_H_

#include "QueryBase.h"
#include "Query.h"
#include <iostream>

class NotQuery: public QueryBase 
{
    friend Query operator~(const Query &);
private:
    NotQuery(Query q): query(q) { }

     // concrete class: NotQuery defines all inherited pure virtual functions
     std::set<line_no> eval(const TextQuery&) const;
     std::ostream& display(std::ostream &os) const
     { return os << "~(" << query << ")"; }

     const Query query;
};

#endif
