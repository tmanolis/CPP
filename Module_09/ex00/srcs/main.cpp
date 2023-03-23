#include "BitcoinExchange.hpp"

# define FILE_PATH "./data.csv"

void findBitcoinRate(std::string date, float value, std::map<std::string, BitcoinExchange> BitcoinExchangeMap)
{
	(void)date;
	(void)value;
	(void)BitcoinExchangeMap;
	// trouver le maillon dans map qui correspond a la date
	// appel a la fonction membre to print la convertion

	// pour checker si jamais on trouve pas la date ; insert puisque tri autonmatique, puis prendre celui d'avant, puis delete
	// BitcoinExchange	new_element("2010-08-24", 2);
	// BitcoinExchangeMap.insert(std::pair<std::string, BitcoinExchange>("2010-08-24",new_element));
}

/**
 * @brief Check if the given date can exist (e.g. 2022-02-30)
 * 
 * - mktime() : time_t mktime (struct tm * timeptr);
 * Returns the value of type time_t that represents the local time described by the tm structure.
 * 
 * The values of the members tm_wday and tm_yday of timeptr are ignored, 
 * and the values of the other members are interpreted even if out of their valid ranges (see struct tm). 
 * For example, tm_mday may contain values above 31, which are interpreted accordingly as the days that follow the last day of the selected month.
 * A call to this function automatically adjusts the values of the members of timeptr if they are off-range.
 * 
 * - localtime() : struct tm * localtime (const time_t * timer);
 * Uses the value pointed by timer to fill a tm structure with the values that represent the corresponding time. (UNIX time stamp)
 * 
 * Useful link : https://koor.fr/C/ctime/struct_tm.wp
 * https://stackoverflow.com/questions/19482378/how-to-parse-and-validate-a-date-in-stdstring-in-c
 */
int		checkDateisValid(int year, int month, int day)
{
	std::cout << "year : " << year << " - month : " << month << " - day : " << day << std::endl;
	// fill the tm struct with our given day, month and year
	struct tm t;
	t.tm_sec = 30;
	t.tm_min = 30;
	t.tm_hour = 0;
    t.tm_mday = day;
	t.tm_mon = month - 1;
	t.tm_year = year - 1900;
	t.tm_isdst = -1;

	// normalize (if tm struct filled is not a valid, mktime() will adjust it):
	time_t when = mktime(&t);
	const struct tm *norm = localtime(&when);
	// the actual date would be:
	// m = norm->tm_mon + 1;
	// d = norm->tm_mday;
	// y = norm->tm_year;
	// e.g. 29/02/2013 would become 01/03/2013

	// validate (is the normalized date still the same than ours?):
	if (norm->tm_mday == day && norm->tm_mon  == month - 1 && norm->tm_year == year - 1900)
		return (SUCCESS);
	else
		return (FAILURE);
}

int		checkInputsAreValid(std::string line, std::string &date, float &value)
{
	size_t		delimiter_pos = line.find('|');
	if (delimiter_pos == std::string::npos)
	{
		std::cerr << "Error: Bad input, expected format : 'date | value'" << std::endl;
		return (FAILURE);
	}

	date = line.substr(0, delimiter_pos);
	// remove whitespace after at the end
	while (!date.empty() && std::isspace(date.back()))
		date.pop_back();
	// check date
	int year, month, day;
	if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
	{
		std::cerr << "Error: Invalid date format => " << date << std::endl;
		return (FAILURE);
	}
	if (checkDateisValid(year, month, day) == FAILURE)
	{
		std::cerr << "Error: Date is invalid => " << date << std::endl;
		return (FAILURE);
	}

	value = atof(line.substr(delimiter_pos + 1, std::string::npos).c_str());
	// check value
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (FAILURE);
	}
	if (value > 1000)
	{
		std::cerr << "Error: number is too large." << std::endl;
		return (FAILURE);
	}
	// std::cout << "date : |" << date << "| / value : |" << value << std::endl;
	return (SUCCESS);
}

void	printBitcoinAmount(std::string file_name, std::map<std::string, BitcoinExchange> BitcoinExchangeMap)
{
	std::ifstream		ifs(file_name.c_str());
	
	if (ifs.is_open() == false || ifs.fail() == true)
	{
		ifs.close();
		throw std::runtime_error(std::string("Failed to open file ") + file_name);
	}

	std::string line;
	std::string date; 
	float 		value;
	while (std::getline(ifs, line))
	{
		std::cout << "line : " << line << std::endl;
		if (checkInputsAreValid(line, date, value) == FAILURE)
			continue ;
		findBitcoinRate(date, value, BitcoinExchangeMap);
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
		float		rate = atof(line.substr(delimiter_pos + 1, std::string::npos).c_str());
		
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
		std::cerr << "Error: Correct usage ./btc <file>" << std::endl;
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
		std::cerr << "Error: " << e.what() << std::endl;
		return (FAILURE);
	}
	
	// print map to check it's filled
	// std::map<std::string, BitcoinExchange>::iterator it = BitcoinExchangeMap.begin();
	// for (int i = 0; i < 10; i++)
	// {
	// 	std::cout << "node : " << i << " / date : |" << it->second.getDate() << "| / rate : " << it->second.getBitcoinRate() << std::endl;
	// 	it++;
	// }

	return (SUCCESS);
}