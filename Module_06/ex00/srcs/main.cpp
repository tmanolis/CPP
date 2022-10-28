#include "Convert.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Convert	convert(argv[1]);
		convert.display();
	}
	else
		std::cerr << "Usage: ./Convert <string>" << std::endl;
	
	return (0);
}