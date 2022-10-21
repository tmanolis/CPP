#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] Default Constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "[Brain] Copy Constructor called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "[Brain] Destructor called" << std::endl;
}

Brain & Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
	{
		
	}
	return (*this);
}

std::string * Brain::getType() const
{
	return (this->_Ideas);
}