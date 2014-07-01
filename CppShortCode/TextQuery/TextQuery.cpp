#include "TextQuery.h"
#include <sstream>
#include <stdexcept>
using namespace std;

//存储文件
void TextQuery::store_file(ifstream &is)
{
	string line;
	while(getline(is, line))
		lines_of_text.push_back(line);
}

//简历单词与行号的对应
void TextQuery::build_map()
{
	line_no lno = 1;
	for(vector<string>::const_iterator iter = lines_of_text.begin();
		iter != lines_of_text.end(); ++iter, ++lno)
	{
		istringstream str(*iter);
		string word;
		while(str>>word)
		{
			word_map[word].insert(lno);
		}
	}
}

//执行查询，返回结果行号
const set<TextQuery::line_no> &TextQuery::run_query
	(const string &queryString) const
{
	static set<line_no> dummy;
	map<string, set<line_no> >::const_iterator iter = 
		word_map.find(queryString);
	if(iter != word_map.end())
	{
		return iter->second;
	}
	else
	{
		return dummy;
	}
}

//返回给定行号对应的内容
const string &TextQuery::text_line(line_no lineno) const
{ 
	if(lineno > lines_of_text.size() | lineno < 1)
	{
		ostringstream ostr;
		ostr<<"Line no.:"<<lineno<<" out of range";
		throw out_of_range(ostr.str());
	}
	return lines_of_text[lineno-1]; 
}
