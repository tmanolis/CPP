#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _Name(name)
{
	std::cout << "HumanB got an name and a weapon" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanA says byyyyyye" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	std::cout << this->_Name << " attacks with their ";
	std::cout << this->_weapon->getType() << std::endl;
}