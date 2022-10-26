#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "colors.hpp"
# include "Form.hpp"
# include <iostream>
# include <cstdlib>

class RobotomyRequestForm : public Form
{
	private:
		std::string	_Target;

	public:
		RobotomyRequestForm();												// Default Constructor
		RobotomyRequestForm(RobotomyRequestForm const &src); 				// Copy Constructor
		virtual ~RobotomyRequestForm();										// Destructor

		RobotomyRequestForm & operator=(RobotomyRequestForm const &rhs); 	// assignement operator overload

		RobotomyRequestForm(std::string target);		// Parametric Constructor

		// Accessors
		std::string	getTarget() const;

		// Public Member Functions
		virtual void	execute(void) const;
	
};

#endif