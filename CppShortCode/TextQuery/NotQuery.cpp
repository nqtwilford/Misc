#include "NotQuery.h"
#include <map>
using namespace std;

// returns lines not in its operand's result set
set<TextQuery::line_no> NotQuery::eval(const TextQuery& file) const
{
	// virtual call through the Query handle to eval
	set<TextQuery::line_no> has_val = query.eval(file);
	set<line_no> ret_lines;
	// for each line in the input file, check whether that line is in has_val
	// if not, add that line number to ret_lines
	for (TextQuery::line_no n = 1; n <= file.size(); ++n)
	{
		if (has_val.find(n) == has_val.end())
			ret_lines.insert(n);
	}
	return ret_lines;
}
