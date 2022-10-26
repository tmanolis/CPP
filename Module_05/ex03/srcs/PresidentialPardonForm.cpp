#include "PresidentialPardonForm.hpp"

/* Constructors & Destructor */

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _Target("Default")
{
	std::cout << "[PresidentialPardonForm] Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src)
{
	std::cout << "[PresidentialPardonForm] Copy Constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _Target(target)
{
	std::cout << "[PresidentialPardonForm] Parametric Constructor called" << std::endl;
}

/* Operator Overload */

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		this->_Target = rhs.getTarget();
	return (*this);
}

/* Accessors */

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_Target);
}

/* Public Member Functions */

void	PresidentialPardonForm::execute() const
{
	std::cout << MAGENTA << this->_Target << " was forgiven by Zaphod Beeblebrox." << RESET << std::endl;
}