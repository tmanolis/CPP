#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &WeaponRef) : _Name(name), weapon(WeaponRef)
{
	std::cout << "HumanA got an name and a weapon" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA says byyyyyye" << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << this->_Name << "attacks with their";
	std::cout << this->weapon.getType() << std::endl;
}