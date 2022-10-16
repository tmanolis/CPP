#include "Fixed.hpp"

int	const Fixed::_nBits = 8;

// *** CONSTRUCTORS & DESTRUCTOR *** //
// Default Constructor 
Fixed::Fixed() : _RawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/**
 * @brief Parametric constructor :
 * Take a int as argument and convert it into a fixed point
 * 
 * Bits shifting allow to place the decimal at the '8bits'
 * (it changes where 2^0 is)
 * @param value int value which will be converted
 */
Fixed::Fixed(int const value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_RawBits = value << _nBits;

}

/**
 * @brief Parametric constructor :
 * Take a float as argument and convert it into a fixed point
 * 
 * Use mantisse and exoosant
 * @param value float value which will be converted
 * 
 * For the conversion check these articles :
 * https://www.positron-libre.com/cours/electronique/systeme-numeration/nombre-virgule-flottante.php
 * https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
 * 
 */
Fixed::Fixed(float const value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_RawBits = (int)roundf(value * (1 << _nBits));
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// Assignment Operator Overload
Fixed & Fixed::operator=(Fixed const &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_RawBits = rhs.getRawBits();
	return (*this);
}

// *** COMPARISON OPERATORS OVERLOAD *** //
// Results when using comparison operator is 
// '1' when it's true, and '0' when it's false
bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->_RawBits > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->_RawBits < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_RawBits >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_RawBits <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->_RawBits == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_RawBits != rhs.getRawBits());
}

// *** ARITHMETIC OPERATORS OVERLOAD *** //
// nota bene : the return line could also be written without precising 'Fixed'
// 				ex : return ((this->toFloat() + rhs.toFloat());
Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

// *** DECREMENTATION & INCREMENTATION OPERATORS OVERLOAD *** //
/**
 * You need to use () or (int) as a suffix to operator++. 
 * This will tell the compiler whether you want the ++ operator to be pre, or postfix.
 * ! Lors de la spécification d’un opérateur surchargé pour la forme postfix de l’opérateur incrément ou décrémentation, 
 * ! l’argument supplémentaire doit être de type int; la spécification d’un autre type génère une erreur.
 * 
 * For more infos check :
 * https://stackoverflow.com/questions/53182109/trying-to-overload-increment-operator-in-c
 * https://learn.microsoft.com/fr-fr/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
 */
Fixed &	Fixed::operator++() // ++i
{
	this->_RawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int) // i++
{
	Fixed	tmp;

	tmp = *this;
	this->_RawBits++;
	return(tmp);
}

Fixed &	Fixed::operator--() // --i
{
	this->_RawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int) // i--
{
	Fixed	tmp;

	tmp = *this;
	this->_RawBits--;
	return(tmp);
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	
	return (this->_RawBits);
}

void 	Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_RawBits / (float)(1 << _nBits));
}

int		Fixed::toInt(void) const
{
	return (this->_RawBits >> _nBits);
}

// Stream Operator Overload
std::ostream & operator<<(std::ostream &o, Fixed const &src)
{
	o << src.toFloat();
	return (o);
}