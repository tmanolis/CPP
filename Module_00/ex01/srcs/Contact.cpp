#include "Contact.hpp"

int Contact::nb_Contacts = 0;

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::get_FirstName(void) const
{
	return (this->_FirstName);
}

static std::string	get_input(void)
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
 * Choose to use getline and not std::cin >> str to handle input with spaces
 * ! if you call std::cin >> var; just before getline(), 
 * ! there will be a newline still remaining in the input stream, 
 * ! after reading the input variable.
 * For more infos and how to handle issue :
 * https://www.digitalocean.com/community/tutorials/getline-in-c-plus-plus
 */

void	Contact::FillContact(void)
{
	std::string	str;
	std::getline(std::cin, str); // avoid the remaining newline in cin

	std::cout << BYEL << "Please enter contact details 📝" << RESET << std::endl;
	std::cout << "• First name : ";
	this->_FirstName = get_input();
	std::cout << "• Last name : ";
	this->_LastName = get_input();
	std::cout << "• Nickname :  ";
	std::cout << BLUE << "(Psst.. don't be shy Teddybear) " << RESET << std::endl << "> ";
	this->_NickName = get_input();
	std::cout << "• Phone number : ";
	this->_PhoneNumber = get_input();
	std::cout << "• Darkest Secret : ";
	this->_DarkestSecret = get_input();
}

void	Contact::PrintContact(void) const
{

}

void	Contact::PrintDetails(void) const
{
	std::cout << "• First name : " << this->_FirstName << std::endl;
	std::cout << "• Last name : " << this->_LastName << std::endl;
	std::cout << "• Nickname : " << this->_NickName << std::endl;
	std::cout << "• Phone number : " << this->_PhoneNumber << std::endl;
	std::cout << "• Darkest Secret : " << this->_DarkestSecret << std::endl;
}
