#include "PhoneBook.hpp"

void	PhoneBook::prompt(void) const
{
	std::cout << UWHT << "Welcome to your Awesome PhoneBook" << RESET << std::endl;
	std::cout << "You can type " << BWHT << "ADD or SEARCH " << RESET;
	std::cout << "to add contacts or search for infos" << std::endl;
	std::cout << "When you're done, type " << BWHT << "EXIT" << RESET << std::endl;
}

PhoneBook::PhoneBook(void)
{
	this->prompt();
	return;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	// if (Contact::nb_Contacts == 8)


	return ;
}

void	PhoneBook::search(void) const
{
	return ;
}
