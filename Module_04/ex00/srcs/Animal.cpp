#include "Animal.hpp"

/* Constructors & Destructor */

Animal::Animal() : _Type("Random Animal")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(Animal const &src) : _Type("Random Animal")
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(std::string type) : _Type(type)
{
	std::cout << "Animal Parametric Constructor called" << std::endl;
}

/* Operator Overload */

Animal & Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_Type = rhs.getType();
	return (*this);
}

/* Accessors */

std::string	Animal::getType() const
{
	return (this->_Type);
}

/* Public Member Functions */
void	Animal::makeSound() const
{
	std::cout << this->_Type << " is making its sound" << std::endl;
}
