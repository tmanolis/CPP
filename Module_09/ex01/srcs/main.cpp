#include "RPN.hpp"


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Correct usage ./RPN <inverted Polish mathematical expression>" << std::endl;
		return (FAILURE);
	}
	
	RPN	rpn;
	try
	{
		rpn.resolve(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (FAILURE);
	}
	// print rpn : faire une surchage d'operateur << pour print le 1er element de la stack :
	// std::cout << rpn << std::endl;
	std::cout << "RESULTAT FINAL :" << rpn.getMystack().top() << std::endl;
	return (SUCCESS);
}