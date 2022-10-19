#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	Unknown;
	FragTrap	Josiane("Josiane");
	ClapTrap	Jackie("Jackie");

	Josiane.attack("Frederick");
	std::cout << "Josiane Energy : " << Josiane.getEnergyPoints() << std::endl << std::endl;
	Josiane.takeDamage(8);
	std::cout << "Josiane HitPoints level : " << Josiane.getHitPoints() << std::endl;
	std::cout << "Josiane Energy : " << Josiane.getEnergyPoints() << std::endl << std::endl;
	Josiane.highFivesGuys();
	Josiane.beRepaired(5);
	std::cout << "Josiane HitPoints level : " << Josiane.getHitPoints() << std::endl;
	std::cout << "Josiane Energy : " << Josiane.getEnergyPoints() << std::endl << std::endl;

	Unknown.takeDamage(105);
	std::cout << "HitPoints level : " << Unknown.getHitPoints() << std::endl;
	std::cout << "Energy : " << Unknown.getEnergyPoints() << std::endl << std::endl;
	Unknown.beRepaired(12);


	std::cout << std::endl;
	Jackie.attack("Omar");
	std::cout << "Jackie Energy : " << Jackie.getEnergyPoints() << std::endl << std::endl;
	Jackie.takeDamage(8);
	std::cout << "Jackie HitPoints level : " << Jackie.getHitPoints() << std::endl;
	std::cout << "Jackie Energy : " << Jackie.getEnergyPoints() << std::endl << std::endl;
	Jackie.beRepaired(5);
	std::cout << "Jackie HitPoints level : " << Jackie.getHitPoints() << std::endl;
	std::cout << "Jackie Energy : " << Jackie.getEnergyPoints() << std::endl << std::endl;
	
	return (0);
}