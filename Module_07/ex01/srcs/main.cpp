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
	
	


	// ::swap( a, b );	// Implicite template instanciation
	// std::cout << "a = " << a << ", b = " << b << std::endl;
	// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;	// Implicite template instanciation
	// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;	// Implicite template instanciation
	
	// std::string c = "chaine1";
	// std::string d = "chaine2";

	// ::swap(c, d); // Implicite template instanciation
	// std::cout << "c = " << c << ", d = " << d << std::endl;
	// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	
	return (0);
}