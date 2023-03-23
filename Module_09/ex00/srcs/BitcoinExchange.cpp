#include "BitcoinExchange.hpp"


/* Constructors & Destructor */

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(std::string date, float rate) : _Date(date), _BitcoinRate(rate)
{

}

/* Accessors */

std::string	BitcoinExchange::getDate() const
{ 
	return(this->_Date);
}

float		BitcoinExchange::getBitcoinRate() const
{
	return(this->_BitcoinRate);
}

/* Member functions */
void	BitcoinExchange::calculateBitcoinAmount(std::string date, float value) const
{
	float amount = this->_BitcoinRate * value;
	std::cout << date << " => " << value << " = " << amount << std::endl;
}