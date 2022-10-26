#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "colors.hpp"
# include "Form.hpp"
# include <iostream>

class PresidentialPardonForm : public Form
{
	private:
		std::string	_Target;

	public:
		PresidentialPardonForm();												// Default Constructor
		PresidentialPardonForm(PresidentialPardonForm const &src); 				// Copy Constructor
		virtual ~PresidentialPardonForm();										// Destructor

		PresidentialPardonForm & operator=(PresidentialPardonForm const &rhs); 	// assignement operator overload

		PresidentialPardonForm(std::string target);		// Parametric Constructor

		// Accessors
		std::string	getTarget() const;

		// Public Member Functions
		virtual void	execute(void) const;
	
};

#endif