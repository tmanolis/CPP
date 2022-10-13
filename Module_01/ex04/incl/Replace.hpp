#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

class Replace
{
private:
	const char			*_FileName;
	std::string	const	_Str1; // string you have to replace
	std::string	const	_Str2; // string you replace with
	std::string			_Content;

public:
	Replace(const char *name, std::string str1, std::string str2);
	~Replace();

	bool	RetrieveFileContent(void);
	void	ReplaceContent(void);
	void	PutContentIntoNewFile(void) const;
};

#endif