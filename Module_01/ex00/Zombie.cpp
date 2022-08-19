#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_Name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_Name << " was killed" << std::endl;
}


void	Zombie::announce(void)
{
	std::cout << this->_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
