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
	std::string	_Content;

public:

	Replace(std::string name, std::string str1, std::string str2);
	~Replace();

	bool	RetrieveFileContent(void);
	void	PutContentIntoNewFile(void) const;
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

// void	Replace::CopyIntoNewFile(void)
// {
// 	std::ifstream		ifs(this->_FileName);
// 	std::stringstream	buffer;
// 	std::ofstream		ofs(this->_FileName + ".replace");

// 	//! Need to protect ifs(this->_FileName) before continuing
// 	buffer << ifs.rdbuf(); // stock file's content into buffer
// 	ofs << buffer.str(); // transform buffer's content in a string and put it into the new file
// 	ifs.close();
// 	ofs.close();
// }

/**
 * @brief Read from a file and put its content into string var
 * 
 * Used infile stream to manipulate the file :
 * - check if error occured when we try link the stream with the file and
 * 	check if is not a directory. 
 * - std::stringstream buffer allows to stock what has been read from ifs, 
 * 	using the member function : rdbuf();
 * - buffer.str() transform content's buffer in a string
 * 
 * useful link : 
 * - https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
 * - https://stackoverflow.com/questions/29310166/check-if-a-fstream-is-either-a-file-or-directory
 */

bool	Replace::RetrieveFileContent(void)
{
	std::ifstream		ifs(this->_FileName);
	std::stringstream	buffer;

	// Check if infile stream encoutered an error
	if (ifs.is_open() == false || ifs.fail() == true)
		return (false);
	// This will set the fail bit if fileName is a directory (or do nothing if it is already set) 
	ifs.seekg(0, std::ios::end);
	if(!ifs.good())
	{
		ifs.close();
		return (false);
	}
	// Stock file's content into buffer, then put it into the newfile
	buffer << ifs.rdbuf();
	// ! PROBLEME CA NE STOCK PAS dans la string
	this->_Content = buffer.str();
	// std::cout << this->_Content << std::endl;
	ifs.close();
	return (true);
}

void	Replace::PutContentIntoNewFile(void) const
{
	std::ofstream		ofs(this->_FileName + ".replace");

	ofs << this->_Content;
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