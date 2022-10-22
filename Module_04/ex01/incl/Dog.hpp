#ifndef	DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_Brain;

	public:
		Dog();						// default constructor
		Dog(Dog const &src);		// copy constructor
		virtual ~Dog();				// destructor

		Dog & operator=(Dog const &rhs); // assignement operator overload

		// Public Member Functions
		virtual void	makeSound() const;
};

#endif
