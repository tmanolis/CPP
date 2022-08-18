#include "PhoneBook.hpp"

void	PhoneBook::_prompt(void) const
{
	std::cout << " 📒 " << UWHT << "Welcome to your Awesome PhoneBook" << RESET << " 📒 " << std::endl;
	std::cout << " You can type " << BWHT << "ADD or SEARCH " << RESET;
	std::cout << "to add contacts or search for infos" << std::endl;
	std::cout << " When you're done, type " << BWHT << "EXIT" << RESET << std::endl;
}

void	PhoneBook::_PrintContactsList(void) const
{
	std::cout << BWHT << "\n              PhoneBook              " << RESET << std::endl;
	std::cout << "|-----------------------------------|" << std::endl;
	std::cout << "|Id|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
		this->_Contact[i].PrintContact(i);
	std::cout << std::endl;
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

void	PhoneBook::add(void)
{
	if (Contact::nb_Contacts < 8)
		Contact::nb_Contacts += 1;
	
	shift_contacts(this->_Contact);
	this->_Contact[0].FillContact();
}

void	PhoneBook::search(void) const
{
	int index;

	if (Contact::nb_Contacts > 0) // avoid infinite loop if 0 contact has been added
	{
		this->_PrintContactsList();
		index = get_index(this->_Contact);
		this->_Contact[index].PrintContactDetails();
	}
	else
		std::cout << BWHT << "No contacts have been added yet" << RESET << std::endl;	
}
