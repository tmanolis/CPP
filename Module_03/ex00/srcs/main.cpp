#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Josiane("Josiane");
	ClapTrap Unknown;

	Josiane.attack("Frederick");
	std::cout << "Josiane Energy : " << Josiane.getEnergyPoints() << std::endl;
	Josiane.takeDamage(8);
	std::cout << "Josiane HitPoints level : " << Josiane.getHitPoints() << std::endl;
	std::cout << "Josiane Energy : " << Josiane.getEnergyPoints() << std::endl;
	Josiane.beRepaired(5);
	std::cout << "Josiane HitPoints level : " << Josiane.getHitPoints() << std::endl;
	std::cout << "Josiane Energy : " << Josiane.getEnergyPoints() << std::endl;

	Unknown.takeDamage(12);
	std::cout << "HitPoints level : " << Unknown.getHitPoints() << std::endl;
	std::cout << "Energy : " << Unknown.getEnergyPoints() << std::endl;
	Unknown.beRepaired(12);
	return (0);
}