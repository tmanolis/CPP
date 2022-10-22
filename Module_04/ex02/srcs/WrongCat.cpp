#include "WrongCat.hpp"

/* Constructors & Destructor */

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

/* Operator Overload */

WrongCat & WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_Type = rhs.getType();
	return (*this);
}

/* Public Member Functions */
void	WrongCat::makeSound() const
{
	std::cout << this->_Type << " is making MIAOOOOOOOOOOWWWWWWW" << std::endl;
}