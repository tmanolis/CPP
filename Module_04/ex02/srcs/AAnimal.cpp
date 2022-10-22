#include "AAnimal.hpp"

/* Constructors & Destructor */

AAnimal::AAnimal() : _Type("Random AAnimal")
{
	std::cout << "[AAnimal] Default Constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) : _Type("Random AAnimal")
{
	std::cout << "[AAnimal] Copy Constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "[AAnimal] Destructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _Type(type)
{
	std::cout << "[AAnimal] Parametric Constructor called" << std::endl;
}

/* Operator Overload */

AAnimal & AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "[AAnimal] Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_Type = rhs.getType();
	return (*this);
}

/* Accessors */

std::string	AAnimal::getType() const
{
	return (this->_Type);
}
