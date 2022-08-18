# include "Contact.hpp"

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

void	Contact::PrintContact(int i) const
{
	std::cout << "| " << i + 1 << "|";
	print_formated_info(this->_FirstName);
	print_formated_info(this->_LastName);
	print_formated_info(this->_NickName);
	std::cout << std::endl;
}

void	Contact::PrintContactDetails(void) const
{
	std::cout << std::endl;
	std::cout << "• First name : " << this->_FirstName << std::endl;
	std::cout << "• Last name : " << this->_LastName << std::endl;
	std::cout << "• Nickname : " << this->_NickName << std::endl;
	std::cout << "• Phone number : " << this->_PhoneNumber << std::endl;
	std::cout << "• Darkest Secret : " << this->_DarkestSecret << std::endl;
}
