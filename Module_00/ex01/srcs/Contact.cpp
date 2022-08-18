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
				std::cout << RED << "Come on.. need some infos mate" << RESET <<std::endl << "> ";
		else
			return str;
	}
}

void	Contact::FillContact(void)
{
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

void	Contact::PrintDetails(void) const
{
	std::cout << "First name : " << this->_FirstName << std::endl;
	std::cout << "Last name : " << this->_LastName << std::endl;
	std::cout << "Nickname : " << this->_NickName << std::endl;
	std::cout << "Phone number : " << this->_PhoneNumber << std::endl;
	std::cout << "Darkest Secret : " << this->_DarkestSecret << std::endl;
}
