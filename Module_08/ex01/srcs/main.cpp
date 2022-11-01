#include "Span.hpp"

int main()
{
	std::cout << BWHT<< "================= Subject Test ===============" << RESET << std::endl;
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.displaySpan();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << BWHT<< "\n================= Exceptions Test ===============" << RESET << std::endl;
	Span	sp1 = Span(10);

	try
	{
		sp1.addNumber(42);
		std::cout << sp1.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	sp1.displaySpan();
	try
	{
		sp1.addPlageNumber(100);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	sp1.displaySpan();
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	std::cout << BWHT<< "\n================= Copy Test ===============" << RESET << std::endl;
	Span	copy(sp1);

	copy.displaySpan();
	std::cout << copy.shortestSpan() << std::endl;
	std::cout << copy.longestSpan() << std::endl;

	std::cout << BWHT<< "\n================= Large Span Test ===============" << RESET << std::endl;
	Span	large(10000);

	try
	{
		large.addPlageNumber(10001);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	// large.displaySpan();
	std::cout << large.shortestSpan() << std::endl;
	std::cout << large.longestSpan() << std::endl;

	return (0);
}