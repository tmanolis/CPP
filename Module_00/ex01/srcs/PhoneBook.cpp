#include "PhoneBook.hpp"

void	PhoneBook::_prompt(void) const
{
	std::cout << " 📒 " << UWHT << "Welcome to your Awesome PhoneBook" << RESET << " 📒 " << std::endl;
	std::cout << " You can type " << BWHT << "ADD or SEARCH " << RESET;
	std::cout << "to add contacts or search for infos" << std::endl;
	std::cout << " When you're done, type " << BWHT << "EXIT" << RESET << std::endl;
}

PhoneBook::PhoneBook(void)
{
	this->_prompt();
	return;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

// Shifts the contacts to the next index
// allows the latest entry to be at the top of the list. 

static void	shift_contacts(Contact *Contacts)
{
	for (int i = Contact::nb_Contacts - 1; i > 0; i--)
		Contacts[i] = Contacts[i - 1];
}

void	PhoneBook::add(void)
{
	if (Contact::nb_Contacts < 8)
		Contact::nb_Contacts += 1;
	
	shift_contacts(this->_Contact);
	this->_Contact[0].FillContact();
	
	return ;
}

void	PhoneBook::search(void) const
{
	for (int i = 0; i < Contact::nb_Contacts; i++)
		this->_Contact[i].PrintDetails();
	return ;
}
