#include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

Weapon::Weapon(std::string type) : _Type(type)
{
}

Weapon::~Weapon()
{
}

std::string const & Weapon::getType(void) const
{
	std::string const	&str = this->_Type;
	return (str);
}

void	Weapon::setType(std::string new_type)
{
	this->_Type = new_type;
}