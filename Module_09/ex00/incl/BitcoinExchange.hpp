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
		std::string	_Date;
		float		_BitcoinRate;

	public:
		BitcoinExchange();								// Default Constructor
		BitcoinExchange(BitcoinExchange const &src);	// Copy Constructor
		~BitcoinExchange();								// Destructor

		BitcoinExchange(std::string date, float rate);	// Parametric Constructor

		// Accessors
		std::string	getDate() const;
		float		getBitcoinRate() const;
		// Member functions
		void		calculateBitcoinAmount() const;

};


#endif

