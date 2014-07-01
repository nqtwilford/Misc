#ifndef _WORDQUERY_H_
#define _WORDQUERY_H_

#include "QueryBase.h"
#include <string>
#include <iostream>

class WordQuery: public QueryBase 
{
	friend class Query; // Query uses the WordQuery constructor
private:
	WordQuery(const std::string &s): query_word(s) { }

	// concrete class: WordQuery defines all inherited pure virtual functions
	std::set<line_no> eval(const TextQuery &t) const
	{ return t.run_query(query_word); }

	std::ostream& display (std::ostream &os) const
	{ return os << query_word; }

	std::string query_word; // word for which to search
};

#endif
