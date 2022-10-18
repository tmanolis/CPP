#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string const	_Name;
	static unsigned int	_HitPoints;
	static unsigned int	_EnergyPoints;
	static unsigned int	_AttackDamage;  

public:
	ClapTrap(); 						// default constructor
	ClapTrap(std::string const name); 	// Parametric constructor
	ClapTrap(ClapTrap const &src);		// copy constructor
	~ClapTrap();						// destructor 

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
