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
	
	if (rpn.getMystack().size() == 1)
	// print rpn : faire une surchage d'operateur << pour print le 1er element de la stack :
	// std::cout << rpn << std::endl;
		std::cout << "Result: " << rpn.getMystack().top() << std::endl;
	else
	{
		std::cerr << "Error: Inverted Polish mathematical expression given is incorrect" << std::endl;
		return (FAILURE);
	}
	return (SUCCESS);
}