#include "WrongAnimal.hpp"

/* Constructors & Destructor */

WrongAnimal::WrongAnimal() : _Type("Random WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) : _Type("Random WrongAnimal")
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _Type(type)
{
	std::cout << "WrongAnimal Parametric Constructor called" << std::endl;
}

/* Operator Overload */

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_Type = rhs.getType();
	return (*this);
}

/* Accessors */

std::string	WrongAnimal::getType() const
{
	return (this->_Type);
}

/* Public Member Functions */
void	WrongAnimal::makeSound() const
{
	std::cout << this->_Type << " is making its wrong random animal sound" << std::endl;
}
