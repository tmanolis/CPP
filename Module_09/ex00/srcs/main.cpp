#include "BitcoinExchange.hpp"

# define FILE_PATH "./data.csv"

// BitcoinExchange	&parseData(std::string line)
void	parseData(std::string line)
{
	size_t		delimiter_pos = line.find(',');
	std::string	date = line.substr(0, delimiter_pos);
	std::string	value = line.substr(delimiter_pos + 1, std::string::npos);
	float		rate = atof(value.c_str());	
 
	std::cout << "date : " << date << " rate : " << rate << std::endl;
	// return (BitcoinExchange	new_element(/*args*/));
}

/**
 * @brief Get data from a file, parse file and fill a map container of BitcoinExchange objects.
 * 
 * Used infile stream to manipulate the file :
 * - if an error occured when we try to link the stream with the file, an exeption is throwned
 * - std::getline() is used to browse the filestream line by line.
 * 		=> getline extracts characters from an input stream until '/n' and places them into a string.
 * 
 * When we browsed the file line by line :
 * - split on comma to get the date and the the corresponding Bitcoin rate.
 * - create a BitcoinExchange object with an arg constructor to store date, and Bitcoin rate.
 * - insert the new object to the map container.
 * 
 * 
 * @param map : std::map<std::string, BitcoinExchange>
 * - key value : date
 * - mapped value : BitcoinExhange object
 * 
 * Useful links :
 * - std::getline() : https://cplusplus.com/reference/string/string/getline/
 * - std::map::insert() : https://cplusplus.com/reference/map/map/insert/
 */
void	fillBitcoinExchangeContainer(std::map<std::string, BitcoinExchange> &map)
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
		std::cout << line << std::endl;
		// split sur la virgule
		parseData(line);
		// BitcoinExchange	new_element = parseData(line);
		// OU BitcoinExchange	new_element(/*args*/);
		
		// mettre dans le map
		// map.insert(std::pair<std::string, BitcoinExchange>('a',new_element) );
		
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
		fillBitcoinExchangeContainer(BitcoinExchange);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return (-1);
	}

	// print map to check it's filled
	
}