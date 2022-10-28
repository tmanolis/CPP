#include "whatever.hpp"

int	main(void)
{
	int a = 2;
	int b = 3;
	
	::swap( a, b );	// Implicite template instanciation
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;	// Implicite template instanciation
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;	// Implicite template instanciation
	
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d); // Implicite template instanciation
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return (0);
}