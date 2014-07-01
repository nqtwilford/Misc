#ifndef _QUERYBASE_H_
#define _QUERYBASE_H_

#include "TextQuery.h"
#include <iostream>

// private, abstract class acts as a base class for concrete query types
class QueryBase {
	friend class Query;

protected:
	typedef TextQuery::line_no line_no;
	virtual ~QueryBase() { }

private:
	// eval returns the |set| of lines that this Query matches
	virtual std::set<line_no> eval(const TextQuery&) const = 0;

	// display prints the query
	virtual std::ostream& display(std::ostream& = std::cout) const = 0;
};

#endif
