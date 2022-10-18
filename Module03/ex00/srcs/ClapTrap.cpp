#include "ClapTrap.hpp"
#include "colors.hpp"

unsigned int	ClapTrap::_HitPoints = 10;
unsigned int	ClapTrap::_EnergyPoints = 10;
unsigned int	ClapTrap::_AttackDamage = 0;

/* Constructors & Destructor */

ClapTrap::ClapTrap() : _Name("THE GIRL HAS NO NAME")
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _Name(name)
{
	std::cout << "Parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

/* Operator Overload */

ClapTrap & ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_HitPoints = rhs.getHitPoints();
		this->_EnergyPoints = rhs.getEnergyPoints();
		this->_AttackDamage = rhs.getAttackDamage();
	}
	return (*this);
}

/* Accessors */

std::string		ClapTrap::getName() const
{
	return (this->_Name);
}
unsigned int	ClapTrap::getHitPoints() const
{
	return (this->_HitPoints);
}
unsigned int	ClapTrap::getEnergyPoints() const
{
	return (this->_EnergyPoints);
}
unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->_AttackDamage);
}

/* Public Member Functions */

void	ClapTrap::attack(const std::string &target)
{
	if (this->_EnergyPoints > 1)
	{
		std::cout << "Clap Trap " << CYAN << this->_Name << RESET;
		std::cout << " attacks " << BWHT << target << RESET;
		std::cout << ", causing " << BRED << this->_AttackDamage << RESET;
		std::cout << " points of damage !" << std::endl;
		
		this->_EnergyPoints--;
	}
	else
	{
		std::cout << "Clap Trap " << CYAN << this->_Name << RESET;
		std::cout << " has no more energy" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{

}

void	ClapTrap::beRepaired(unsigned int amount)
{

}
