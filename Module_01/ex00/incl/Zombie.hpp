#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	
	std::string	_Name;

public:
	
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
};

#endif