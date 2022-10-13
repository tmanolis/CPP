#include "Fixed.hpp"

int	const Fixed::_nBits = 0;

// Default Constructor 
Fixed::Fixed() : _RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Parametric constructor
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;

}

// Parametric constructor
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;

}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Assignment Operator Overload
Fixed & Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_RawBits = rhs.getRawBits();
	
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	
	return (this->_RawBits);
}

void 	Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
}

float	Fixed::toFloat(void) const
{

}

int		Fixed::toInt(void) const
{

}

// Stream Overload Operator
std::ostream & operator<<(std::ostream &o, Fixed const &src)
{
	o << src.toFloat();

	return (o);
}