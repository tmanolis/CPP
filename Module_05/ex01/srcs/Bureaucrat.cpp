#include "Bureaucrat.hpp"

/* Constructors & Destructor */

Bureaucrat::Bureaucrat() : _Name("Random Jean-Jacques"), _Grade(150)
{
	std::cout << "[Bureaucrat] Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "[Bureaucrat] Copy Constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _Name(name), _Grade(grade)
{
	std::cout << "[Bureaucrat] Parametric Constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

/* Operator Overload */

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_Grade = rhs.getGrade();
	return (*this);
}

/* Accessors */

std::string	Bureaucrat::getName() const
{
	return (this->_Name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_Grade);
}

/* Public Member Functions */
void	Bureaucrat::promote()
{
	if (_Grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_Grade--;

}

void	Bureaucrat::demote()
{
	if (_Grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_Grade++;
		
}

/* Exceptions */

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

/* Stream Operator Overload */

std::ostream & operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << BCYN << src.getName() << RESET << ", bureaucrat grade ";
	o << MAGENTA << src.getGrade() << RESET << ".";
	return (o);
}
