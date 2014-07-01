#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

#include <fstream>
#include <vector>
#include <set>
#include <map>

//因为头文件会被其他文件包含，最好不要使用using namespace
class TextQuery 
{
public:
	// typedef to make declarations easier
	typedef std::vector<std::string>::size_type line_no;
	/* interface:
	* read_file builds internal data structures for the given file
	* run_query finds the given word and returns set of lines on which it appears
	* text_line returns a requested line from the input file
	*/
	void read_file(std::ifstream &inputFileStream)
	{ 
		store_file(inputFileStream); 
		build_map(); 
	}
	const std::set<line_no> &run_query(const std::string &queryString) const;
	const std::string &text_line(line_no lineno) const;
	line_no size() const
	{
		return lines_of_text.size();
	}
private:
	// utility functions used by read_file
	void store_file(std::ifstream&); // store input file
	void build_map(); // associated each word with a set of line numbers
	// remember the whole input file
	std::vector<std::string> lines_of_text;
	// map word to set of the lines on which it occurs
	std::map< std::string, std::set<line_no> > word_map;
};

#endif
