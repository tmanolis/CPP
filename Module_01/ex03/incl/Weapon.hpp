#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
private:
	std::string	_Type;

public:
	Weapon(std::string type);
	~Weapon();
	Weapon();

	std::string const & getType(void) const;
	void				setType(std::string new_type);

};

#endif