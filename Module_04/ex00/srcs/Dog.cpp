#include "Dog.hpp"

/* Constructors & Destructor */

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

/* Operator Overload */

Dog & Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_Type = rhs.getType();
	return (*this);
}

/* Public Member Functions */
void	Dog::makeSound() const
{
	std::cout << this->_Type << " (Hugo) is barking at your face" << std::endl;
}