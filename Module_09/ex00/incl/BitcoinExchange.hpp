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
# include <ctime>

class BitcoinExchange
{
	private:
		std::string	_Date;
		float		_BitcoinRate;

	public:
		BitcoinExchange();											// Default Constructor
		BitcoinExchange(BitcoinExchange const &src);				// Copy Constructor
		~BitcoinExchange();											// Destructor

		BitcoinExchange(std::string date, float rate);				// Parametric Constructor

		// Operator Overload
		BitcoinExchange & operator=(BitcoinExchange const &rhs);
		// Accessors
		std::string	getDate() const;
		float		getBitcoinRate() const;
		// Member functions
		void		calculateBitcoinAmount(std::string date, float value) const;

};

#endif

