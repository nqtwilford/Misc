#ifndef _QUERY_H_
#define _QUERY_H_

#include "TextQuery.h"
#include "QueryBase.h"
#include "WordQuery.h"
#include <string>
#include <set>

// handle class to manage the Query_base inheritance hierarchy
class Query {
	// these operators need access to the Query_base* constructor
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	// builds a new WordQuery
	Query(const std::string &s): 
		q(new WordQuery(s)), use(new std::size_t(0))
	{
		++*use;
	}

	// copy control to manage pointers and use counting
	Query(const Query &c): q(c.q), use(c.use) 
	{ ++*use; }

	~Query() { decr_use(); }

	Query& operator=(const Query&);

	// interface functions: will call corresponding QueryBase operations
	std::set<TextQuery::line_no> eval(const TextQuery &t) const 
	{ return q->eval(t); }

	std::ostream &display(std::ostream &os) const
	{ return q->display(os); }

private:
	Query(QueryBase *query): 
	q(query), use(new std::size_t(1)) 
	{ }

	void decr_use()
	{ 
		if (--*use == 0) 
		{ 
			delete q; 
			delete use; 
		} 
	}

	QueryBase *q;
	std::size_t *use;
};

std::ostream &operator <<(std::ostream &os, const Query &q);

#endif
