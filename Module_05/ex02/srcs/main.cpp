#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	// std::cout << "\n------------------ Robotomy Request Forms ------------------" << std::endl;
	// Form*			RobotomyForm = new RobotomyRequestForm("Robotomy");
	
	// std::cout << "\n------------------ Presidential Pardon Forms ------------------" << std::endl;
	// Form*			PresidentialForm = new PresidentialPardonForm("Presidential");

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
	
	

	// std::cout << std::endl << "\n================== Test on Shrubbery Creation Form ====================" << std::endl;
	// std::cout << "------------------ Execution without Signature ------------------" << std::endl;
	// try {
	// 	s1->execute(k);
	// }
	// catch (AForm::RequirementException e)
	// {
	// 	e.printErr();
	// }

	// std::cout << "\n------------------ Signature ------------------" << std::endl;
	// try {
	// 	s1->beSigned(g);
	// }
	// catch (AForm::GradeTooLowException e)
	// {
	// 	e.printErr();
	// }
	// std::cout << std::endl << *s1 << std::endl;
	// s1->beSigned(k);
	// std::cout << *s1;

	// std::cout << "\n------------------ Execution with Signature ------------------" << std::endl;
	// try {
	// 	s1->execute(g);
	// }
	// catch (AForm::RequirementException e)
	// {
	// 	e.printErr();
	// }
	// s1->execute(k);
	// delete RobotomyForm;
	// delete PresidentialForm;


	// std::cout << std::endl << BWHT << "============ [Bureaucrat 💼 & Form 📝] Basic Test  ============" << RESET << std::endl;
	// try 
	// {
	// 	Bureaucrat	Pam("Pam", 70);
	// 	std::cout << Pam << std::endl;
	// 	Form	Boring("Boring", 70, 150); 
	// 	std::cout << Boring << std::endl;
	// 	Pam.signForm(Boring);
	// 	std::cout << Boring << std::endl;
	// 	Pam.signForm(Boring);
	// }
	// catch (std::exception &e)
	// {
	// 	  std::cout << BRED << e.what() << RESET << std::endl;
	// }

	// std::cout << std::endl;
	// try 
	// {
	// 	Bureaucrat	Pam("Pam", 70);
	// 	std::cout << Pam << std::endl;
	// 	Form	Relou("Relou", 69, 150); 
	// 	std::cout << Relou << std::endl;
	// 	Pam.signForm(Relou);
	// }
	// catch (std::exception &e)
	// {
	// 	  std::cout << BRED << e.what() << RESET << std::endl;
	// }

	return (0);
}