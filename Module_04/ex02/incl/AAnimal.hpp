#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/**
 * @brief Abstract Class :
 * An abstract class in C++ is one that has at least one pure virtual function by definition. 
 * In other words, a function that has no definition. 
 * The abstract class's descendants must define the pure virtual function; 
 * otherwise, the subclass would become an abstract class in its own right.
 */
class AAnimal
{
	protected:
		std::string		_Type;

	public:
		AAnimal();						// default constructor
		AAnimal(AAnimal const &src);	// copy constructor
		virtual ~AAnimal();				// destructor 

		AAnimal(std::string type);		// parametric constructor

		AAnimal & operator=(AAnimal const &rhs); // assignement operator overload

		// Accessors
		std::string		getType() const;

		// Public Member Functions
		virtual void	makeSound() const = 0;
};

#endif