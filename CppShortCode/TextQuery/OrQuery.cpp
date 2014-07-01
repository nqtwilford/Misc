#include "OrQuery.h"
#include "TextQuery.h"
#include <set>
using namespace std;

// returns union of its operands' result sets
set<TextQuery::line_no> OrQuery::eval(const TextQuery &file) const
{
	// virtual calls through the Query handle to get result sets for the operands
	set<line_no> right = rhs.eval(file),
				ret_lines = lhs.eval(file); // destination to hold results
	// inserts the lines from right that aren't already in ret_lines
	ret_lines.insert(right.begin(), right.end());

	return ret_lines;
}
