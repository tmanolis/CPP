#include "Form.hpp"

static void	checkGrade(int grade) 
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

/* Constructors & Destructor */

Form::Form() : 
	_Name("Random Form"), _IsSigned(false), _SignGrade(150), _ExecGrade(150)
{
	std::cout << "[Form] Default Constructor called" << std::endl;
}

Form::Form(Form const &src) :
	_Name(src._Name), _IsSigned(src._IsSigned), _SignGrade(src._SignGrade), _ExecGrade(src._ExecGrade)
{
	std::cout << "[Form] Copy Constructor called" << std::endl;
	// *this = src; ???
}

Form::~Form()
{
	std::cout << "[Form] Destructor called" << std::endl;
}

Form::Form(std::string const name, bool isSigned, int const signGrade, int const execGrade) : 
	_Name(name), _IsSigned(isSigned), _SignGrade(signGrade), _ExecGrade(execGrade)
{
	std::cout << "[Form] Parametric Constructor called" << std::endl;
	checkGrade(this->_SignGrade);
	checkGrade(this->_ExecGrade);
}

/* Operator Overload */

Form & Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		this->_IsSigned = rhs.getIsSigned();
	return (*this);
}

/* Accessors */

std::string	Form::getName() const
{
	return (this->_Name);
}

bool	Form::getIsSigned() const
{
	return (this->_IsSigned);
}

int	Form::getSignGrade() const
{
	return (this->_SignGrade);
}

int	Form::getExecGrade() const
{
	return (this->_ExecGrade);
}

/* Public Member Functions */


/* Exceptions */

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

/* Stream Operator Overload */

std::ostream & operator<<(std::ostream &o, Form const &src)
{
	o << UYEL << "Form" + src.getName() << RESET << std::endl;
	o << "• Grade required to sign : " << src.getSignGrade() << std::endl;
	o << "• Grade required to execute : " << src.getExecGrade() << std::endl;
	// Ternary : has to be entre parenthese to work with stream
	o << "• Status : " << ((src.getIsSigned() == true) ? "signed." : "not signed.") << std::endl; 

	return (o);
}
