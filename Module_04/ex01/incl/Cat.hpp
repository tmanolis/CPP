#ifndef	CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_Brain;

	public:
		Cat();						// default constructor
		Cat(Cat const &src);		// copy constructor
		virtual ~Cat();				// destructor

		Cat & operator=(Cat const &rhs); // assignement operator overload

		// Accessors
		Brain		*getBrain() const;

		// Public Member Functions
		virtual void	makeSound() const;

};

#endif