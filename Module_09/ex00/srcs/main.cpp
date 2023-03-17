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

void	fillBitcoinExchange(std::map<std::string, BitcoinExchange> &map)
{
	(void)map;

	std::ifstream		ifs(FILE_PATH);
	std::stringstream	buffer;

	if (ifs.is_open() == false || ifs.fail() == true)
		throw std::runtime_error(std::string("Failed to open file ") + FILE_PATH);
	
	std::string line;
	int i = 0;
	while (std::getline(ifs, line) && i < 4)
	{
		// split sur la virgule et mettre dans le map
		std::cout << line << std::endl;
		i++;
	}
	
	// close and return
	ifs.close();
}

int	main(void)
{
	std::map<std::string, BitcoinExchange>	BitcoinExchange;

	try
	{
		fillBitcoinExchange(BitcoinExchange);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return (-1);
	}
	
}