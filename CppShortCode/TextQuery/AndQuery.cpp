#include "AndQuery.h"
#include "TextQuery.h"
#include <map>
#include <algorithm>
using namespace std;

// returns intersection of its operands' result sets
set<TextQuery::line_no> AndQuery::eval(const TextQuery& file) const
{
	// virtual calls through the Query handle to get result sets for the operands
	set<line_no> left = lhs.eval(file),
			    right = rhs.eval(file);
	set<line_no> ret_lines; // destination to hold results
	// writes intersection of two ranges to a destination iterator
	// destination iterator in this call adds elements to ret
	set_intersection(left.begin(), left.end(),
				right.begin(), right.end(),
				inserter(ret_lines, ret_lines.begin()));
	return ret_lines;
}
