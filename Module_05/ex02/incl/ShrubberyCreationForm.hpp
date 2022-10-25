#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "colors.hpp"
# include "Form.hpp"
# include <iostream>
# include <fstream>

class ShrubberyCreationForm : public Form
{
	private:
		std::string	_Target;

	public:
		ShrubberyCreationForm();											// Default Constructor
		ShrubberyCreationForm(ShrubberyCreationForm const &src); 			// Copy Constructor
		virtual ~ShrubberyCreationForm();									// Destructor

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &rhs); 	// assignement operator overload

		ShrubberyCreationForm(std::string target);		// Parametric Constructor

		// Accessors
		std::string	getTarget() const;

		// Public Member Functions
		virtual void	execute(void) const;
	
};

#endif