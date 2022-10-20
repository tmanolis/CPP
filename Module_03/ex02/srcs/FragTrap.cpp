#include "FragTrap.hpp"

/**
 * @brief Useful links to more infos on inheritance :
 * 
 * https://www.geeksforgeeks.org/inheritance-in-c/
 * https://stackoverflow.com/questions/120876/what-are-the-rules-for-calling-the-base-class-constructor
 * 
 */

/* Constructors & Destructor */

FragTrap::FragTrap()
{
	std::cout << "Default Constructor called : FragTrap " << this->_Name << " created" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called : " << this->_Name << " is copied" << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called for " << this->_Name << std::endl;
}

/**
 * @brief Call a ClapTrap's parametric constructor that use initialization list
 * 
 * This way if the value already initialized were const it will be possible to change their values
 * c.f: talk with Ben
 */
FragTrap::FragTrap(std::string const name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "Parametric Constructor called : FragTrap " << name << " created" << std::endl;
}

/* Operator Overload */

FragTrap & FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
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

void	FragTrap::highFivesGuys()
{
	std::cout << std::endl << YELLOW << "HEYYYY my dudes GIMME A HIGH FIVE yeahhhh 🤙🤙🤙 ";
	std::cout << "(CASSDEDI to my best pal Maryyyyyyyyne)" << RESET << std::endl << std::endl;
}
