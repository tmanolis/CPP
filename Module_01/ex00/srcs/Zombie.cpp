#include "Zombie.hpp"

/**
 * @brief Construct a new Zombie:: Zombie object 
 * 	and initialise private var _Name.
 * 
 * The syntax used here is "initialization list".
 * 
 * Constructor could have written also like that :
 * Zombie::Zombie(std::string name)
 *	{
 *		this->_Name = name;
 *		std::cout << this->_Name << " is born" << std::endl;
 *	}
 * 
 * @param name : string given as a arg to the constructor,
 * 				will be attribuate to _Name.
 * 
 */

Zombie::Zombie(std::string name) : _Name(name)
{
	std::cout << this->_Name << " is born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_Name << " was killed" << std::endl;
}


void	Zombie::announce(void)
{
	std::cout << this->_Name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
