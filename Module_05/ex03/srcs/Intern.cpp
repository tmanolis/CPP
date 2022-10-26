#include "Intern.hpp"

static Form	*createForm(std::string formName, std::string target)
{
	int					i = 0;
	Form* 				newForm;
	const std::string	validForms[3] = {"ShrubberyCreationForm", 
									"RobotomyRequestForm", 
									"PresidentialPardonForm"};
	
	//Check if the form whose is trying to be created exist
	while (i < 3 && validForms[i] != formName)
		i++;

	switch (i) 
	{
		case 0: newForm = new ShrubberyCreationForm(target); break;
		case 1: newForm = new RobotomyRequestForm(target); break;
		case 2: newForm = new PresidentialPardonForm(target); break;
		default: throw Intern::UnknownFormException();
	}
	std::cout << BLUE << "Intern creates " + newForm->getName() << RESET << std::endl;
	return (newForm);
}

/* Constructors & Destructor */

Intern::Intern()
{
	std::cout << "[Intern] Default Constructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << "[Intern] Copy Constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "[Intern] Destructor called" << std::endl;
}

/* Operator Overload */

Intern & Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

/* Public Member Functions */

Form *	Intern::makeForm(std::string formName, std::string target)
{
	Form	*newForm;
	
	try
	{
		newForm = createForm(formName, target);
	}
	catch(std::exception & e)
	{
		std::cerr << RED << "Intern couldn't create " << formName << " because ";
		std::cerr << e.what() << RESET << std::endl;
		return (NULL);
	}
	return (newForm);
}

/* Exceptions */

const char * Intern::UnknownFormException::what() const throw()
{
	return ("this form does not exist.");
}