#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include "colors.hpp"

class ClapTrap
{
protected:
	std::string 	_Name;
	unsigned int	_HitPoints;
	unsigned int	_EnergyPoints;
	unsigned int	_AttackDamage;  

public:
	ClapTrap(); 						// default constructor
	ClapTrap(ClapTrap const &src);		// copy constructor
	~ClapTrap();						// destructor 

	ClapTrap(std::string const name); 	// Parametric constructor
	ClapTrap(std::string const name, unsigned int hit, unsigned int energy, unsigned int attackDam);
	
	ClapTrap & operator=(ClapTrap const &rhs);	// assignment operator overload

	//Accessors
	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackDamage() const;
	
	// Public Member Functions
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};

#endif 
