#ifndef	WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string		_Type;

	public:
		WrongAnimal();							// default constructor
		WrongAnimal(WrongAnimal const &src);	// copy constructor
		virtual ~WrongAnimal();					// destructor 

		WrongAnimal(std::string type);			// parametric constructor

		WrongAnimal & operator=(WrongAnimal const &rhs); // assignement operator overload

		// Accessors
		std::string		getType() const;

		// Public Member Functions
		void	makeSound() const;
};

#endif