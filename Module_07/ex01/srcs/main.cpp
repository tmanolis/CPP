#include "iter.hpp"

// Colors
# define RESET "\e[0m"
# define CYAN "\e[0;36m"
# define BWHT "\e[1;37m"

int	main(void)
{
	std::cout << BWHT<< "================= Int Array ===============" << RESET << std::endl;
	int intArray[5] = {0, 1, 2, 3, 4};
	iter<int>(intArray, 5, print);		// Explicite template instanciation
	iter(intArray, 5, increment);		// Implicite template instanciation
	std::cout << "/* After incrementation */" << std::endl;
	iter(intArray, 5, print);
	
	std::cout << BWHT<< "\n================= Float Array ===============" << RESET << std::endl;
	float floatArray[3] = {0.42f, 1.42f, 2.42f};
	iter<float>(floatArray, 3, print);		// Explicite template instanciation
	iter(floatArray, 3, increment);		// Implicite template instanciation
	std::cout << "/* After incrementation */" << std::endl;
	iter(floatArray, 3, print);

	std::cout << BWHT<< "\n================= String Array ===============" << RESET << std::endl;
	std::string	strArray[3] = {"Salut", "les", "nazes"};
	iter<std::string>(strArray, 3, print);		// Explicite template instanciation
	

	return (0);
}