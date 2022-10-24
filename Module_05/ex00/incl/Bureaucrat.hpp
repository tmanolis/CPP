#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	private:
		std::string const	_Name;
		int					_Grade;

	public:
		Bureaucrat();							// Default Constructor
		Bureaucrat(Bureaucrat const &src); 		// Copy Constructor
		~Bureaucrat();							// Destructor

		Bureaucrat & operator=(Bureaucrat const &rhs); 	// assignement operator overload

		// Accessors
		std::string	getName() const;
		int			getGrade() const;

		// Public Member Functions


};

/* Constructors & Destructor */

Bureaucrat::Bureaucrat()
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

/* Operator Overload */

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_Name = rhs.getName();
		this->_Grade = rhs.getGrade();
	}
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


#endif