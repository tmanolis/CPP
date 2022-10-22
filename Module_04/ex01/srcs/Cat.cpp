#include "Cat.hpp"

/* Constructors & Destructor */

Cat::Cat() : Animal("Cat")
{
	std::cout << "[Cat] Default Constructor called" << std::endl;
	this->_Brain = new Brain();
}

/**
 * @brief Copy Constructor : Deep VS Shallow Copy
 * When memory is allocated, like in the Class for brain, we need to create a Deep Copy
 * to avoid to point on the same memory address.
 * 
 * Usefull links : 
 * https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/
 * https://www.geeksforgeeks.org/copy-constructor-in-cpp/
 */
Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "[Cat] Copy Constructor called" << std::endl;
	this->_Type = src.getType();
	this->_Brain = new Brain(*src.getBrain());
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
	{
		this->_Type = rhs.getType();
		if (this->_Brain)
			delete this->_Brain;
		this->_Brain = new Brain(*rhs.getBrain());
	}
	return (*this);
}

/* Accessors */

Brain * Cat::getBrain() const
{
	return (this->_Brain);
}

/* Public Member Functions */
void	Cat::makeSound() const
{
	std::cout << this->_Type << " is making MIAOOOOOOOOOOWWWWWWW" << std::endl;
}

void Cat::fillBrain(size_t index, std::string str)
{
	this->_Brain->setIdea(index, str);
}

void	Cat::printBrain()
{
	std::string const *BrainIdeas = this->_Brain->getIdeas();
	
	std::cout << "Index 0 : " << BrainIdeas[0] << std::endl;
}