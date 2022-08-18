#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << std::endl << BCYN << "Please enter a command :" << RESET << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT" || std::cin.eof())
			break ;
		else
			std::cout << RED << cmd << " is not a valid entry." << RESET << std::endl;
	}
	return 0;
}