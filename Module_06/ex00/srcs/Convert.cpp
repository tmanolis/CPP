#include "Convert.hpp"

/* Constructors & Destructor */

Convert::Convert()
{
	std::cout << "[Convert] Default Constructor called" << std::endl;
}

Convert::Convert(Convert const &src)
{
	std::cout << "[Convert] Copy Constructor called" << std::endl;
	*this = src;
}

Convert::~Convert()
{
	std::cout << "[Convert] Destructor called" << std::endl;
}

Convert::Convert(char const *str) : _isValidInt(true), _isValidChar(true), _isPrintableChar(true)
{
	std::cout << "[Convert] Parametric Constructor called" << std::endl;

	// Find value type (order is important : isChar must be in the end)
	if (isInt(str) == false && isFloat(str) == false 
		&& isDouble(str) == false && isChar(str) == false)
			this->_type = UNVALID;
	// Cast value into other types based on the type found
	this->castIntoTypes();
	// Check if values should be displayed and set flags according to
	this->setDisplayFlags();
}

/* Operator Overload */

Convert & Convert::operator=(Convert const &rhs)
{
	if (this != &rhs)
	{
		this->_int = rhs._int;
		this->_double = rhs._double;
		this->_float = rhs._float;
		this->_char = rhs._char;
		this->_isValidInt = rhs._isValidInt;
		this->_isValidChar = rhs._isValidChar;
		this->_isPrintableChar = rhs._isPrintableChar;
	}
	return (*this);
}

/* Public Member Functions */

/**
 * @brief strtol :
 * Parses the C-string str interpreting its content as an integral number of the specified base, 
 * which is returned as a long int value. 
 * If endptr is not a null pointer, the function also sets the value of endptr to point to 
 * the first character after the number.
 * 
 * @param str : C-string beginning with the representation of an integral number.
 * @param endptr : Reference to an object of type char*, whose value is set by the function to the next character in str after the numerical value.
 * This parameter can also be a null pointer, in which case it is not used.
 * @param base : Numerical base (radix) that determines the valid characters and their interpretation.
 * 
 */
bool	Convert::isInt(char const *str)
{
	char	*endptr = NULL;
	long	value = strtol(str, &endptr, 10);

	if (*endptr || value > INT_MAX || value < INT_MIN)
		return (false);
	this->_type = INT;
	this->_int = static_cast<int>(value); // cast because value was a long (to check INT_MIN & INT_MAX)
	return (true);
}

bool	Convert::isFloat(char const *str)
{
	char	*endptr = NULL;
	float	value = strtof(str, &endptr);

	// after the end of decimal number, 'f' should be the first char found and be followed by the end of the str
	if (*endptr != 'f' || *(endptr + 1) != 0)
		return (false);
	this->_type = FLOAT;
	this->_float = value;
	return (true);
}

bool	Convert::isDouble(char const *str)
{
	char	*endptr = NULL;
	double	value = strtod(str, &endptr);

	if (*endptr)
		return (false);
	this->_type = DOUBLE;
	this->_double = value;
	return (true);
}

bool	Convert::isChar(char const *str)
{
	char	value = str[0];

	if (str[1] != 0 || !std::isprint(value))
		return (false);
	this->_type = CHAR;
	this->_char = value;
	return (true);
}

void	Convert::castIntoTypes()
{
	switch (this->_type)
	{
	case (CHAR):
		this->_int = static_cast<int>(this->_char);
		this->_float = static_cast<float>(this->_char);
		this->_double = static_cast<double>(this->_char);
		break;
	case (INT):
		this->_char = static_cast<char>(this->_int);
		this->_float = static_cast<float>(this->_int);
		this->_double = static_cast<double>(this->_int);
		break;
	case (FLOAT):
		this->_char = static_cast<char>(this->_float);
		this->_int = static_cast<int>(this->_float);
		this->_double = static_cast<double>(this->_float);
		break;
	case (DOUBLE):
		this->_char = static_cast<char>(this->_double);
		this->_float = static_cast<float>(this->_double);
		this->_int = static_cast<int>(this->_double);
		break;
	default:
		this->_isValidInt = false;
		this->_isValidChar = false;
		this->_float = NAN;
		this->_double = NAN;
		break;
	}
}

void	Convert::setDisplayFlags()
{
	if (this->_double < INT_MIN || this->_double > INT_MAX
		|| std::isnan(this->_double) || std::isinf(this->_double))
	{
		this->_isValidInt = false;
		this->_isValidChar = false;
	}
	else if (this->_double < CHAR_MIN || this->_double > CHAR_MAX)
	{
		this->_isValidChar = false;
	}
	else if (std::isprint(this->_char) == false)
	{
		this->_isPrintableChar = false;
	}
}

/**
 * @brief about std::fixed and std::setprecision
 * 
 * When floatfield is set to fixed, floating-point values are written using fixed-point notation: 
 * the value is represented with exactly as many digits in the decimal part as specified by the precision field (precision) 
 * and with no exponent part.
 * 
 */
void	Convert::display() const
{
	std::cout << std::fixed << std::setprecision(1);

	// CHAR
	std::cout << "char: ";
	if (this->_isValidChar == false)
		std::cout << "impossible" << std::endl;
	else if (this->_isPrintableChar == false)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << _char << "'" << std::endl;
	
	// INT
	std::cout << "int: ";
	if (this->_isValidInt == false)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _int << std::endl;
	
	// FLOAT
	std::cout << "float: " << _float << "f" << std::endl;
	
	// DOUBLE
	std::cout << "double: " << _double << std::endl;
}
