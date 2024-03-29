#ifndef	DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();						// default constructor
		Dog(Dog const &src);		// copy constructor
		~Dog();						// destructor

		Dog & operator=(Dog const &rhs); // assignement operator overload

		// Public Member Functions
		virtual void	makeSound() const;
};

#endif
