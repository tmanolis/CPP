#include "Brain.hpp"

/* Constructors & Destructor */

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

/* Operator Overload */

Brain & Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_Ideas[i] = rhs._Ideas[i];
	}
	return (*this);
}

/* Accessors */

std::string const * Brain::getIdeas() const
{
	return (this->_Ideas);
}

void	Brain::setIdea(size_t index, std::string arg)
{
	if (index < 100)
		this->_Ideas[index] = arg;
}
