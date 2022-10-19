#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "colors.hpp"

class FragTrap : public ClapTrap
{
private:
	
public:
	FragTrap(); 						// default constructor
	FragTrap(FragTrap const &src);		// copy constructor
	~FragTrap();						// destructor 

	FragTrap(std::string const name); 	// Parametric constructor

	FragTrap & operator=(FragTrap const &rhs);	// assignment operator overload

	void	highFivesGuys(void);
};

#endif
