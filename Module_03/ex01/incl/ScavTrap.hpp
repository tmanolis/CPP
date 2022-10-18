#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "colors.hpp"

class ScavTrap : public ClapTrap
{
private:
	
public:
	ScavTrap(); 						// default constructor
	ScavTrap(ScavTrap const &src);		// copy constructor
	~ScavTrap();						// destructor 

	ScavTrap(std::string const name); 	// Parametric constructor

	ScavTrap & operator=(ScavTrap const &rhs);	// assignment operator overload

	void	attack(const std::string &target);
	void	guardGate();
};

#endif
