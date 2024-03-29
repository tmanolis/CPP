#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "colors.hpp"
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_Name;
		bool				_IsSigned;
		int	const			_SignGrade;
		int	const			_ExecGrade;

	public:
		Form();							// Default Constructor
		Form(Form const &src); 			// Copy Constructor
		virtual ~Form();				// Destructor

		Form & operator=(Form const &rhs); 	// assignement operator overload

		Form(std::string const name, int const signGrade, int const execGrade);	// Parametric Constructor

		// Accessors
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		// Public Member Functions
		void			beSigned(Bureaucrat const &bureaucrat);
		void			execute(Bureaucrat const &executor) const;
		virtual void	execute(void) const = 0;

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
		class FormNotSignedException : public std::exception 
		{
			public :
				virtual const char * what() const throw();
		};

		
};

std::ostream & operator<<(std::ostream &o, Form const &src);

#endif