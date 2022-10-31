#include "easyfind.hpp"
#include <vector>

int	main(void)
{
	int needle = 42;

	std::cout << BWHT << "*~~~~~~~~~~~~~~ No Occurence ~~~~~~~~~~~~~~*" << RESET << std::endl;
	{
		std::vector<int>	haystack(100, 7);

		easyfind(haystack, needle);
	}

	std::cout << BWHT << "\n*~~~~~~~~~~~~~~ With Occurence (in the first element) ~~~~~~~~~~~~~~*" << RESET << std::endl;
	{
		std::vector<int>	haystack(100, 42);
		
		easyfind(haystack, needle);
	}

	std::cout << BWHT << "\n*~~~~~~~~~~~~~~ With Occurence ~~~~~~~~~~~~~~*" << RESET << std::endl;
	{
		std::vector<int>	haystack;

		haystack.push_back(1);
		haystack.push_back(2);
		haystack.push_back(42);
		haystack.push_back(3);
		easyfind(haystack, needle);
	}

	return (0);
}