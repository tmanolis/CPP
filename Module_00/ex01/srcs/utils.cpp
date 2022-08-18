#include "PhoneBook.hpp"

//* UTILS FOR PHONEBOOK CLASS FUNCTIONS *//

/**
 * @brief Shift the contacts to the next index
 * allows the latest entry to be at the top of the list.
 * 
 * @param Contacts : static array of 8 class Contact
 */

void	shift_contacts(Contact *Contacts)
{
	for (int i = Contact::nb_Contacts - 1; i > 0; i--)
		Contacts[i] = Contacts[i - 1];
}

/**
 * @brief Get the index
 * This function will loop until a valid index is entered :
 * - check if index is between 1 and 8
 * - check if a contact at this index has been added.
 * 
 *  Used getline to avoid issues if spaces are entered
 * 
 * @param Contact : used to check if the contact at the index entered
 * 					is not empty
 * @return A valid index
 */

int	get_index(const Contact *Contact)
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
				std::cout << RED << "This contact is empty\n" << RESET << std::endl;
			else
				return (index - 1);
		}
		else
			std::cout << RED << str << " isn't valid dude\n" << RESET << std::endl;
	}
}

//* UTILS FOR PHONEBOOK FUNCTIONS *//

/**
 * Choose to use getline and not std::cin >> str to handle input with spaces
 * ! if you call std::cin >> var; just before getline(), 
 * ! there will be a newline still remaining in the input stream, 
 * ! after reading the input variable.
 * For more infos and how to handle issue :
 * https://www.digitalocean.com/community/tutorials/getline-in-c-plus-plus
 */

std::string	get_input(void)
{
	std::string	str;

	while (1)
	{
		std::getline(std::cin, str);
		if (std::cin.fail())
		{	
			std::cin.clear();
			std::cin.ignore();
			exit(-1);
		}
		if (str.empty())
				std::cout << BWHT << "Come on.. need some infos mate" << RESET <<std::endl << "> ";
		else
			return str;
	}
}

/**
 * @brief change the format of the input stream
 * and trunc the str if it has more than 10 chars
 * 
 * @param str is a copy of the contact info that need to be print
 * (ex : FirstName, LastName, etc...)
 */

void	print_formated_info(std::string str)
{
	std::cout << std::setw(10);
	if (str.length() > 10)
		str = str.substr(0, 9) + "."; // "+" operator append the following string
	std::cout << str << "|";

}