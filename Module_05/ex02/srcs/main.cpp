#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "\n================== 🌳 Test on Shrubbery Creation Form 🌳 ====================" << std::endl;
	std::cout << "------------------ Bureaucrats ------------------" << std::endl;
	Bureaucrat	gardener("gardener", 138);
	std::cout << gardener << std::endl;
	
	std::cout << "------------------ Shrubbery Creation Forms ------------------" << std::endl;
	ShrubberyCreationForm	ShrubberyForm("Shrubbery");
	std::cout << ShrubberyForm << std::endl;

	std::cout << "\n------------------ Execution without Signature ------------------" << std::endl;
	gardener.executeForm(ShrubberyForm);

	std::cout << "------------------ Signature ------------------" << std::endl;
	gardener.signForm(ShrubberyForm);

	std::cout << "------------------ Execution without Grade ------------------" << std::endl;
	gardener.executeForm(ShrubberyForm);

	std::cout << "------------------ Working Execution ------------------" << std::endl;
	gardener.promote();
	gardener.executeForm(ShrubberyForm);
	

	std::cout << "\n================== 🤖 Test on Robotomy Request Form 🤖 ====================" << std::endl;
	std::cout << "------------------ Bureaucrats ------------------" << std::endl;
	Bureaucrat	Jack("Jack", 45);
	std::cout << Jack << std::endl;
	
	std::cout << "------------------ Robotomy Creation Forms ------------------" << std::endl;
	RobotomyRequestForm	RobotForm("Random Victim");
	std::cout << RobotForm << std::endl;

	std::cout << "------------------ Signature ------------------" << std::endl;
	Jack.signForm(RobotForm);

	std::cout << "------------------ Working Execution ------------------" << std::endl;
	Jack.executeForm(RobotForm);


	std::cout << "\n================== Test on Presidential Pardon Form ====================" << std::endl;
	std::cout << "------------------ Bureaucrats ------------------" << std::endl;
	Bureaucrat	Xavier("Xavier", 1);
	std::cout << Xavier << std::endl;
	
	std::cout << "------------------ Robotomy Creation Forms ------------------" << std::endl;
	PresidentialPardonForm	PresidentForm("Vincent");
	std::cout << PresidentForm << std::endl;

	std::cout << "------------------ Signature ------------------" << std::endl;
	Xavier.signForm(PresidentForm);

	std::cout << "------------------ Working Execution ------------------" << std::endl;
	Xavier.executeForm(PresidentForm);	


	std::cout << std::endl;
	return (0);
}