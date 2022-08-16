#include <iostream>
#include "PhoneBook.hpp"
#include "colors.hpp"

void	prompt(void)
{
	std::cout << UWHT << "Welcome to your Awesome PhoneBook" << RESET << std::endl;
	std::cout << "You can type " << BWHT << "ADD or SEARCH " << RESET;
	std::cout << "to add contacts or search for infos" << std::endl;
	std::cout << "When you're done, type " << BWHT << "EXIT" << RESET << std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	prompt();
	while (1)
	{
		std::cout << std::endl << BCYN << "Please enter a command :" << RESET << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT")
			std::exit(0);
		else
			std::cout << RED << cmd << " is not a valid entry." << RESET << std::endl;
	}

	return 0;
}