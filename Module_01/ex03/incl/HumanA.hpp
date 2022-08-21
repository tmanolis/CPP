#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string const	_Name;
	Weapon	&_weapon;

public:

	HumanA(std::string name, Weapon &WeaponRef);
	~HumanA();

	void	attack(void) const;
};

#endif