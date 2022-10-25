#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{

	// std::cout << std::endl << BWHT << "============ [Form 📝] Test Grade to Construct  ============" << RESET << std::endl;
	// try 
	// {
	// 	Form	Boring("Boring", 160, 1); // WRONG : SignGrade to high
	// }
	// catch (std::exception &e)
	// {
	// 	  std::cout << RED << e.what() << RESET << std::endl;
	// }

	// try 
	// {
	// 	Form	Boring("Boring", 2, -8); // WRONG : ExecGrade to low
	// }
	// catch (std::exception &e)
	// {
	// 	  std::cout << RED << e.what() << RESET << std::endl;
	// }

	// try 
	// {
	// 	Form	Boring("Boring", 200, 0); // WRONG : Both grade are wrong
	// }
	// catch (std::exception &e)
	// {
	// 	  std::cout << RED << e.what() << RESET << std::endl;
	// }

	// try 
	// {
	// 	Form	Boring("Boring", 2, 150); // OK
	// 	std::cout << Boring << std::endl;

	// }
	// catch (std::exception &e)
	// {
	// 	  std::cout << RED << e.what() << RESET << std::endl;
	// }

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