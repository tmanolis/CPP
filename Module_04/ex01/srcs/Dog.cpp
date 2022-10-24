#include "Dog.hpp"

/* Constructors & Destructor */

Dog::Dog() : Animal("Dog")
{
	std::cout << "[Dog] Default Constructor called" << std::endl;
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
Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "[Dog] Copy Constructor called" << std::endl;
	this->_Type = src.getType();
	this->_Brain = new Brain(*src.getBrain());
}

/**
 * @brief What happened when delete is call on _Brain ?
 * When delete is used to deallocate memory for a C++ class object, 
 * the object's destructor is called before the object's memory is 
 * deallocated (if the object has a destructor).
 */
Dog::~Dog()
{
	std::cout << "[Dog] Destructor called" << std::endl;
	delete this->_Brain;
}

/* Operator Overload */

Dog & Dog::operator=(Dog const &rhs)
{
	std::cout << "[Dog] Copy assignment operator called" << std::endl;
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

Brain * Dog::getBrain() const
{
	return (this->_Brain);
}

/* Public Member Functions */

void	Dog::makeSound() const
{
	std::cout << this->_Type << " (Hugo) is barking at your face" << std::endl;
}