#include <cstdlib>
#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand(time(NULL));
	int	i = (std::rand() % 3) + 1;		// Range to 1 to 3 
	
	switch (i)
	{
		case 1:
			std::cout << "Pointer to Class A is returned" << std::endl;
			return (new A);
		case 2:
			std::cout << "Pointer to Class B is returned" << std::endl;
			return (new B);
		case 3:
			std::cout << "Pointer to Class C is returned" << std::endl;
			return (new C);
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

// Using try and catch cause a ref can't be NULL 
 void identify(Base& p)
 {
	try
	{
		A classA = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::bad_cast &bc) {}
	try
	{
		B classB = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch(std::bad_cast &bc) {}
	try
	{
		C classC = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch(std::bad_cast &bc) {}
 }

int	main (void)
{
	Base	*basePtr;

	basePtr = generate();
	std::cout << "[PTR] - The object pointed by test is : ";
	identify(basePtr);
	std::cout << std::endl << "[REF] - The object pointed by test is : ";
	identify(*basePtr);

	delete basePtr;
	return (0);
}
