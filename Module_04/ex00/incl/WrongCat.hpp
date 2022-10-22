#ifndef	WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();						// default constructor
		WrongCat(WrongCat const &src);	// copy constructor
		virtual ~WrongCat();			// destructor

		WrongCat & operator=(WrongCat const &rhs); // assignement operator overload

		// Public Member Functions
		void	makeSound() const;
};

#endif