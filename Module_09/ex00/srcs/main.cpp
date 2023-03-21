#include "BitcoinExchange.hpp"

# define FILE_PATH "./data.csv"

// int		inputsAreValid(std::string date, std::string value)
// {

// 	if (value_str.find('.') == string::npos && )

// 	// float		value = atof(value_str.c_str());

// }

void	printBitcoinAmount(std::string file_name, std::map<std::string, BitcoinExchange> BitcoinExchangeMap)
{
	(void)BitcoinExchangeMap;
	std::ifstream		ifs(file_name.c_str());
	
	if (ifs.is_open() == false || ifs.fail() == true)
	{
		ifs.close();
		throw std::runtime_error(std::string("Failed to open file ") + file_name);
	}
	
	std::string line;
	while (std::getline(ifs, line))
	{
		std::cout << "line : " << line << std::endl;
		size_t		delimiter_pos = line.find('|');
		std::string	date = line.substr(0, delimiter_pos);
		std::string	value_str = line.substr(delimiter_pos + 1, std::string::npos);
		// if (inputsAreValid(date, value) == FAILURE)
		// 	return ;
		float		value = atof(value_str.c_str());
		
		std::cout << "date : " << date << " / value : " << value << std::endl;
		
		// trouver le maillon dans map qui correspond a la date
		// appel a la fonction membre to print la convertion


	}
	ifs.close();
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

	if (ifs.is_open() == false || ifs.fail() == true)
	{
		ifs.close();
		throw std::runtime_error(std::string("Failed to open file ") + FILE_PATH);
	}
	
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

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error : Correct usage ./btc <file>" << std::endl;
		return (FAILURE);
	}

	std::map<std::string, BitcoinExchange>	BitcoinExchangeMap;
	try
	{
		fillBitcoinExchange(BitcoinExchangeMap);
		printBitcoinAmount(argv[1], BitcoinExchangeMap);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return (FAILURE);
	}

	// pour checker si jamais on trouve pas la date ; insert puisque tri autonmatique, puis prendre celui d'avant, puis delete
	// BitcoinExchange	new_element("2010-08-24", 2);
	// BitcoinExchangeMap.insert(std::pair<std::string, BitcoinExchange>("2010-08-24",new_element));
	
	// print map to check it's filled
	std::map<std::string, BitcoinExchange>::iterator it = BitcoinExchangeMap.begin();
	for (int i = 0; i < 10; i++)
	{
		std::cout << "node : " << i << " / date : " << it->second.getDate() << " / rate : " << it->second.getBitcoinRate() << std::endl;
		it++;
	}

	return (SUCCESS);
}