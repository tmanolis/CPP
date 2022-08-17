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

void	Contact::FillContact(void)
{
	std::cout << BYEL << "Please enter contact details 📝" << RESET << std::endl;
	std::cout << "• First name : ";
	std::cin >> this->_FirstName;
	std::cout << "• Last name : ";
	std::cin >> this->_LastName;
	std::cout << "• Nickname :  ";
	std::cout << BLUE << "(Psst.. don't be shy Teddybear) " << RESET << std::endl;
	std::cin >> this->_NickName;
	std::cout << "• Phone number : ";
	std::cin >> this->_PhoneNumber;
	std::cout << "• Darkest Secret : ";
	std::cin >> this->_DarkestSecret;
}

void	Contact::PrintDetails(void) const
{
	std::cout << "First name : " << this->_FirstName << std::endl;
}