#include "Zombie.hpp"

Zombie::Zombie()
{
		std::cout << "A zombie is joining the Horde" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_Name << " was killed" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_Name = name;
}

void	Zombie::announce(void) const
{
	std::cout << this->_Name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
