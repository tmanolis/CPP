#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string const	_Name;

public:

	Weapon	&weapon;

	HumanA(std::string name, Weapon &WeaponRef);
	~HumanA();

	void	attack(void) const;
};

#endif