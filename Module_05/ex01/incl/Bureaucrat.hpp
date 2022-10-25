#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "colors.hpp"

class Form; // Can not <# include "Form.hpp"> because "bureaucrate.hpp" is already included in "form.hpp"

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

		Bureaucrat(std::string const name, int grade);	// Parametric Constructor

		// Accessors
		std::string	getName() const;
		int			getGrade() const;

		// Public Member Functions
		void	promote();
		void	demote();
		void	signForm(Form &form) const;

		// Exceptions (Nested Class)
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &src);

#endif