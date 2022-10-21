#include "Cat.hpp"

/* Constructors & Destructor */

Cat::Cat() : Animal("Cat")
{
	std::cout << "[Cat] Default Constructor called" << std::endl;
	this->_Brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "[Cat] Copy Constructor called" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called" << std::endl;
	delete this->_Brain;
}

/* Operator Overload */

Cat & Cat::operator=(Cat const &rhs)
{
	std::cout << "[Cat] Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_Type = rhs.getType();
	return (*this);
}

/* Public Member Functions */
void	Cat::makeSound() const
{
	std::cout << this->_Type << " is making MIAOOOOOOOOOOWWWWWWW" << std::endl;
}