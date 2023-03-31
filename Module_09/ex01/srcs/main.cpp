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
	
	return (SUCCESS);
}