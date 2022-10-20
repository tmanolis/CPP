#include "ClapTrap.hpp"
#include "colors.hpp"

/* Constructors & Destructor */

ClapTrap::ClapTrap() : _Name("THE GIRL HAS NO NAME"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "Default Constructor called : ClapTrap " << this->_Name << " created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor called : " << this->_Name << " is copied" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for " << this->_Name << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "Parametric Constructor called : ClapTrap " << this->_Name << " created" << std::endl;
}

/* Operator Overload */

ClapTrap & ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_Name = rhs.getName();
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
	if (this->_HitPoints <= 0)
	{
		std::cout << "Clap Trap " << CYAN << this->_Name << RESET;
		std::cout << " can't attack cuz is dead 💀" << std::endl;
		return ;
	}
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
	int is_overflow = amount;

	if (this->_HitPoints == 0)
	{
		std::cout << "Clap Trap " << CYAN << this->_Name << RESET;
		std::cout << " can't take more damages cuz is already dead 💀" << std::endl;
		return ;
	}
	if (is_overflow < 0)
	{
		std::cout << "Such a noob... negative damages dafuqqqqq" << std::endl;
		return ;
	}
	std::cout << "Clap Trap " << CYAN << this->_Name << RESET;
	std::cout << " takes " << BRED << amount << RESET;
	std::cout << " points of damage !" << std::endl;
	if (amount > this->_HitPoints)
	{
		std::cout << "Clap Trap " << CYAN << this->_Name << RESET;
		std::cout << " died 💀" << std::endl;
		this->_HitPoints = 0;
	}
	else
		this->_HitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int is_overflow = amount;

	if (this->_HitPoints == 0)
	{
		std::cout << "Clap Trap " << CYAN << this->_Name << RESET;
		std::cout << " can't repair itself cuz is dead 💀" << std::endl;
		return ;
	}
	if (is_overflow < 0)
	{
		std::cout << "Are you trying to kill me mate ?" << std::endl;
		return ;
	}
	if (this->_EnergyPoints > 1)
	{
		std::cout << "Clap Trap " << CYAN << this->_Name << RESET;
		std::cout << " gets " << BRED << amount << RESET;
		std::cout << " of Hit Points back !" << std::endl;
		this->_EnergyPoints--;
		this->_HitPoints += amount;
	}
	else
	{
		std::cout << "Clap Trap " << CYAN << this->_Name << RESET;
		std::cout << " has no more energy" << std::endl;
	}
}
