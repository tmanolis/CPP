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

/**
 * @brief Shift the contacts to the next index
 * allows the latest entry to be at the top of the list.
 * 
 * @param Contacts : static array of 8 class Contact
 */

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
}

/**
 * @brief Get the index
 * This function will loop until a valid index is entered :
 * - check if index is between 1 and 8
 * - check if a contact at this index has been added.
 * 
 * * Used getline to avoid issues if spaces are entered
 * 
 * @param Contact : used to check if the contact at the index entered
 * 					is not empty
 * @return A valid index
 */

static int	get_index(const Contact *Contact)
{
	int 		index;
	std::string	str;

	std::getline(std::cin, str); // avoid the remaining newline in cin
	while (1)
	{
		std::cout << BWHT << "Enter an index for more details : " << RESET;
		getline(std::cin, str);
		index = atoi(str.c_str()); // convert std::str in a const char*
		if (index > 0 && index < 9)
		{
			str = Contact[index - 1].get_FirstName();
			if (str.empty())
				std::cout << RED << "This contact is empty" << RESET << std::endl;
			else
				return (index - 1);
		}
		else
			std::cout << RED << str << " isn't valid dude" << RESET << std::endl;
	}
}

void	PhoneBook::search(void) const
{
	int index;

	for (int i = 0; i < Contact::nb_Contacts; i++)
		this->_Contact[i].PrintContact();

	if (Contact::nb_Contacts > 0) // avoid infinite loop if 0 contact has been added
	{
		index = get_index(this->_Contact);
		this->_Contact[index].PrintDetails();
	}
	else
		std::cout << BWHT << "No contacts have been added yet" << RESET << std::endl;	
}
