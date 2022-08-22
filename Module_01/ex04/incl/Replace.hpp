#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Replace
{
private:
	std::string	const _FileName;
	std::string	const _Str1; // string you have to replace
	std::string	const _Str2; // string you replace with

public:

	Replace(std::string name, std::string str1, std::string str2);
	~Replace();

	void	CopyIntoNewFile(void);
};

/**
 * @brief Read from a file and put its content into a new one
 * 
 * Used infile and outfile stream to manipulate both files.
 * - std::stringstream buffer allows to stock what has been read from ifs, 
 * 	using the member function : rdbuf();
 * - buffer.str() transform content's buffer in a string
 * 
 * useful link : https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
 */

void	Replace::CopyIntoNewFile(void)
{
	std::ifstream		ifs(this->_FileName);
	std::stringstream	buffer;
	std::ofstream		ofs(this->_FileName + ".replace");

	buffer << ifs.rdbuf(); // stock file's content into buffer
	ofs << buffer.str(); // transform buffer's content in a string and put it into the new file
	ifs.close();
	ofs.close();
}

Replace::Replace(std::string name, std::string str1, std::string str2) : _FileName(name), _Str1(str1), _Str2(str2)
{
	std::cout << "FileName : " << this->_FileName << std::endl;
	std::cout << "Str1 : " << this->_Str1 << std::endl;
	std::cout << "Str2 : " << this->_Str2 << std::endl;
}

Replace::~Replace()
{
}

#endif