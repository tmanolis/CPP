#include "ScavTrap.hpp"

/* Constructors & Destructor */

ScavTrap::ScavTrap()
{
	std::cout << "Default Constructor called : ScavTrap " << this->_Name << " created" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "ScavTrap Copy constructor called : " << this->_Name << " is copied" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called for " << this->_Name << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "Parametric Constructor called : ScavTrap " << name << " created" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
}

/* Operator Overload */

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_Name = rhs.getName();
		this->_HitPoints = rhs.getHitPoints();
		this->_EnergyPoints = rhs.getEnergyPoints();
		this->_AttackDamage = rhs.getAttackDamage();
	}
	return (*this);
}

/* Public Member Functions */

void	ScavTrap::attack(const std::string &target)
{
	
}

void	ScavTrap::guardGate()
{
	std::cout << "est ce que tu as la ref des claptrap ou pas tu pues" << std::endl;
}
