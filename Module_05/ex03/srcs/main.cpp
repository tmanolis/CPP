#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << BWHT << "\n================== 💼 Bureaucrat - 📝 Form - 🖨️  Intern  ====================" << RESET << std::endl;
	std::cout << "------------------ Constructors ------------------" << std::endl;
	Bureaucrat	JeanMierre("JeanMierre", 5);
	Intern		Hugo;
	Form		*form;
	
	std::cout << std::endl;
	std::cout << "\n------------------ 🌳 Shrubbery Creation Forms 🌳 ------------------" << std::endl;
	ShrubberyCreationForm	Shrubbery;
	form = Hugo.makeForm(Shrubbery.getName(), "forest");
	std::cout << *form << std::endl;
	JeanMierre.signForm(*form);
	JeanMierre.executeForm(*form);
	delete form;

	std::cout << "\n------------------ 🤖 Robotomy Creation Forms 🤖 ------------------" << std::endl;
	RobotomyRequestForm	Robot;
	form = Hugo.makeForm(Robot.getName(), "Hugo");
	std::cout << *form << std::endl;
	delete form;

	std::cout << "\n------------------ 👨‍💼 Presidental Creation Forms 👨‍💼 ------------------" << std::endl;
	form = Hugo.makeForm("PresidentialPardonForm", "Hugo");
	std::cout << *form << std::endl;
	JeanMierre.signForm(*form);
	JeanMierre.executeForm(*form);
	delete form;

	std::cout << "\n------------------ Wrong Form ------------------" << std::endl;
	form = Hugo.makeForm("WrongForm", "Random");

	std::cout << std::endl;
	std::cout << "------------------ Destructors ------------------" << std::endl;
	return (0);
}