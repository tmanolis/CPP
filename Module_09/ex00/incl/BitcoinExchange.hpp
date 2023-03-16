#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# define SUCCESS 0
# define FAILURE -1

# include <string>
# include <cstdlib>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>


class BitcoinExchange
{
	private:
		// float		_bitcoinRate;
		std::string	_date;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();

};


#endif

