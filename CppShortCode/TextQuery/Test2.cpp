#include "Query.h"
#include "TextQuery.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

TextQuery tq;

void print(TextQuery::line_no lno)
{
	cout<<lno<<":"<<tq.text_line(lno)<<endl;
}


int main(int argc, char **argv)
{
	ifstream in("infile.txt");
	tq.read_file(in);
	Query qry = ( Query("fiery") & Query("bird") | Query("wind") ) & ~Query("Her");
	const set<TextQuery::line_no> &lines = qry.eval(tq);
	cout<<qry<<endl;
	for_each(lines.begin(), lines.end(), print);
	
	return 0;
}
