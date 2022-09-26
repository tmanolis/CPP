#include "Harl.hpp"

int	main(void)
{
	Harl	Harl;
	std::string	level;

	std::cout << UYEL << "Please enter a level of complaint:" << RESET <<std::endl;
	std::cout << " DEBUG, INFO, WARNING or ERROR" << std::endl;
	std::cin >> level;
	Harl.complain(level);
	return (0);
}