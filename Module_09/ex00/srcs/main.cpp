#include "BitcoinExchange.hpp"

# define FILE_PATH "./data.csv"

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
 * - create a BitcoinExchange object with a parametric constructor to store date, and Bitcoin rate.
 * - insert the new object in the map container.
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
void	fillBitcoinExchange(std::map<std::string, BitcoinExchange> &map)
{
	std::ifstream		ifs(FILE_PATH);
	std::stringstream	buffer;

	if (ifs.is_open() == false || ifs.fail() == true)
		throw std::runtime_error(std::string("Failed to open file ") + FILE_PATH);
	
	std::string line;
	while (std::getline(ifs, line))
	{
		// Parse line
		size_t		delimiter_pos = line.find(',');
		std::string	date = line.substr(0, delimiter_pos);
		std::string	value = line.substr(delimiter_pos + 1, std::string::npos);
		float		rate = atof(value.c_str());
		
		// add a new element into the map container
		BitcoinExchange	new_element(date, rate);
		map.insert(std::pair<std::string, BitcoinExchange>(date,new_element));
	}
	ifs.close();
}

int	main(void)
{
	std::map<std::string, BitcoinExchange>	BitcoinExchangeMap;

	try
	{
		fillBitcoinExchange(BitcoinExchangeMap);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return (FAILURE);
	}

	// print map to check it's filled
	// std::map<std::string, BitcoinExchange>::iterator it = BitcoinExchangeMap.begin();
	// for (int i = 0; i < 5; i++)
	// {
	// 	std::cout << "node : " << i << " / date : " << it->second.getDate() << " / rate : " << it->second.getBitcoinRate() << std::endl;
	// 	it++;
	// }

	return (SUCCESS);
}