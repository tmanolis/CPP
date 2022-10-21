#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/**
 * @brief on vitural destructor :
 * In simple terms, a virtual destructor ensures that when derived subclasses go out of scope or are deleted the order 
 * of destruction of each class in a hierarchy is carried out correctly. If the destruction order of the class objects 
 * is incorrect, in can lead to memory leak.
 * 
 * Useful links :
 * https://www.quantstart.com/articles/C-Virtual-Destructors-How-to-Avoid-Memory-Leaks/
 * https://stackoverflow.com/questions/2198379/are-virtual-destructors-inherited
 */
class Animal
{
	protected:
		std::string		_Type;

	public:
		Animal();						// default constructor
		Animal(Animal const &src);		// copy constructor
		virtual ~Animal();				// destructor 

		Animal(std::string type);		// parametric constructor

		Animal & operator=(Animal const &rhs); // assignement operator overload

		// Accessors
		std::string		getType() const;

		// Public Member Functions
		virtual void	makeSound() const;
};

#endif