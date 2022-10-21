#ifndef	CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();						// default constructor
		Cat(Cat const &src);		// copy constructor
		~Cat();						// destructor

		Cat & operator=(Cat const &rhs); // assignement operator overload

		// Public Member Functions
		virtual void	makeSound() const;
};

#endif