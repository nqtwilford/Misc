#ifndef _ORQUERY_H_
#define _ORQUERY_H_

#include "BinaryQuery.h"
#include <map>

class OrQuery: public BinaryQuery 
{
	friend Query operator|(const Query &, const Query &);
private:
	OrQuery(Query left, Query right): BinaryQuery(left, right, "|") { }
	// concrete class: OrQuery inherits display and defines remaining pure virtual
	std::set<line_no> eval(const TextQuery&) const;
};
#endif
