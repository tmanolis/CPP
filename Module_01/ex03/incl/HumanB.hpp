#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string const	_Name;
	Weapon				*_weapon;

public:


	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon &weapon);
	void	attack(void) const;
};

#endif