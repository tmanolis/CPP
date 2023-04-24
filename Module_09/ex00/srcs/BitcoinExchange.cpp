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

/* Operator Overload */

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		this->_Date = rhs.getDate();
		this->_BitcoinRate = rhs.getBitcoinRate();
	}
	return (*this);
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