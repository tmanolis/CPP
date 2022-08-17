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
}

void	Contact::PrintDetails(void) const
{
	std::cout << "First name : " << this->_FirstName << std::endl;
}