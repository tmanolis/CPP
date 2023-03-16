#include "BitcoinExchange.hpp"

# define FILE_PATH "./data.csv"


/**
 * @brief Read from a file and return its content in a string
 * 
 * Used infile stream to manipulate the file :
 * - check if error occured when we try to link the stream with the file.
 * - std::stringstream buffer allows to stock what has been read from ifs, 
 * 	using the member function : rdbuf().
 * - buffer.str() transform content's buffer in a string.
 * 
 * useful link : 
 * https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
 * @return std::string : file's content OR nothing if errors occurs when the file was maniplated 		
 */
std::string	getFileContent(void)
{
	std::ifstream		ifs(FILE_PATH);
	std::stringstream	buffer;

	if (ifs.is_open() == false || ifs.fail() == true)
		return ("");
	buffer << ifs.rdbuf();
	ifs.close();

	return (buffer.str());
}

int	main(void)
{
	std::string	fileContent = getFileContent();
	if (fileContent.empty() == true)
	{
		std::cout << "An error with the data file occured." << std::endl;
		return (FAILURE);
	}
	
}