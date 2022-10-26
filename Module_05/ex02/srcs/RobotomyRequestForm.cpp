#include "RobotomyRequestForm.hpp"

/* Constructors & Destructor */

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _Target("Default")
{
	std::cout << "[RobotomyRequestForm] Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src)
{
	std::cout << "[RobotomyRequestForm] Copy Constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _Target(target)
{
	std::cout << "[RobotomyRequestForm] Parametric Constructor called" << std::endl;
}

/* Operator Overload */

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		this->_Target = rhs.getTarget();
	return (*this);
}

/* Accessors */

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_Target);
}

/* Public Member Functions */

/**
 * @brief Rand function : int rand (void);
 * Returns a pseudo-random integral number in the range between 0 and RAND_MAX each time it is called.
 * This algorithm uses a seed to generate the series, which should be initialized to some distinctive 
 * value using function srand.
 * 
 * example :
 * v1 = rand() % 100;         // v1 in the range 0 to 99
 * v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
 * v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
 */
void	RobotomyRequestForm::execute() const
{
	srand(time(0));
	std::cout << "BzzzZZZZZzzzZZzzzZZ 🔩" << std::endl;
	if ((rand() % 2) == 0) 
	{
		std::cout << BWHT << this->_Target + " has been robotomised !" << RESET << std::endl;
	} 
	else 
	{
		std::cout << "Robotomy failed on " + this->_Target << std::endl;
	}
}