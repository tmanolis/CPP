#include "Replace.hpp"

Replace::Replace(const char *name, std::string str1, std::string str2) : _FileName(name), _Str1(str1), _Str2(str2)
{
	std::cout << "FileName : " << this->_FileName << std::endl;
	std::cout << "String to Replace : " << this->_Str1 << std::endl;
	std::cout << "String to Replace with : " << this->_Str2 << std::endl;
}

Replace::~Replace()
{
}

/**
 * @brief Read from a file and put its content into string var
 * 
 * Used infile stream to manipulate the file :
 * - check if error occured when we try link the stream with the file.
 * - std::stringstream buffer allows to stock what has been read from ifs, 
 * 	using the member function : rdbuf().
 * - buffer.str() transform content's buffer in a string.
 * 
 * useful link : 
 * https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
 */
bool	Replace::RetrieveFileContent(void)
{
	std::ifstream		ifs(this->_FileName);
	std::stringstream	buffer;

	// Check if infile stream encoutered an error
	if (ifs.is_open() == false || ifs.fail() == true)
		return (false);
	// Stock file's content into buffer, then put it into a string
	buffer << ifs.rdbuf();
	this->_Content = buffer.str();
	ifs.close();
	return (true);
}

/**
 * @brief Replace substring Str1 by subtring Str2 in the string _Content
 * 
 * - Used string::find to searches the string for the first occurrence of the sequence specified :
 * 		find() returns 'std::string::npos' if there are no occurrences.
 * - std::string::replace is forbidden, used erase and insert instead.
 */
void	Replace::ReplaceContent(void)
{
	if(this->_Str1.empty())
        return;
	
    size_t start_pos;
	start_pos = this->_Content.find(this->_Str1, 0);

    while(start_pos != std::string::npos)
	{
		// Replace 'Str1' by 'Str2'
		this->_Content.erase(start_pos, this->_Str1.length());
		this->_Content.insert(start_pos, this->_Str2);
        // Look for another occurence of 'Str1' in '_Content'
        start_pos += this->_Str2.length(); // In case 'Str2' contains 'Str1'
		start_pos = this->_Content.find(this->_Str1, start_pos);
    }
}

void	Replace::PutContentIntoNewFile(void) const
{
	std::string		Newfile = (std::string)this->_FileName + ".replace";
	std::ofstream	ofs(Newfile.c_str()); // c.str() convert string into const char*

	ofs << this->_Content;
	ofs.close();
}