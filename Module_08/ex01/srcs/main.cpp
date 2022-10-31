#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(3);
	sp.addNumber(6);
	sp.addNumber(9);
	sp.addNumber(10);

	Span sp1(3);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << sp.longestSpan() << std::endl;

	sp.addMaxRange();
	std::cout << "OK MAX RANGE" << std::endl;
	sp.addMaxRange();
	sp1.addMaxRange();
	std::cout << "OK MAX RANGE" << std::endl;
	sp1.addMaxRange();
	return (0);
}