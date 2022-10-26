#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>

class Intern
{
public:
	Intern();									// Default Constructor			
	Intern(Intern const &src);					// Copy Constructor
	~Intern();									// Destructor

	Intern & operator=(Intern const &rhs); 		// Assignement operator overload

	// Public Member Functions
	Form	*makeForm(std::string formName, std::string target);

	// Exceptions (Nested Class)
	class UnknownFormException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
};


#endif