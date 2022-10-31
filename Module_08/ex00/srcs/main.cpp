#include "easyfind.hpp"
#include <vector>
#include <list>

int	main(void)
{
	int needle = 42;

	std::cout << BWHT<< "================= Int Vector ===============" << RESET << std::endl;

	std::cout << "\n*~~~~~~~~~~~~~~ No Occurence ~~~~~~~~~~~~~~*" << std::endl;
	{
		std::vector<int>	haystack(100, 7);

		easyfind(haystack, needle);
	}
	std::cout << "\n*~~~~~~~~~~~~~~ With Occurence (in the first element) ~~~~~~~~~~~~~~*" << std::endl;
	{
		std::vector<int>					haystack(100, 42);
		std::vector<int>::const_iterator	occurence;
		
		occurence = easyfind(haystack, needle);
		std::cout << "Position of this occurence is: " << occurence - haystack.begin() << std::endl;
	}
	std::cout << "\n*~~~~~~~~~~~~~~ With Occurence ~~~~~~~~~~~~~~*" << std::endl;
	{
		std::vector<int>					haystack;
		std::vector<int>::const_iterator	occurence;

		haystack.push_back(1);
		haystack.push_back(2);
		haystack.push_back(42);
		haystack.push_back(3);
		occurence = easyfind(haystack, needle);
		std::cout << "Position of this occurence is: " << occurence - haystack.begin() << std::endl;
	}


	std::cout << BWHT<< "\n\n================= Int List ===============" << RESET << std::endl;
	std::cout << "\n*~~~~~~~~~~~~~~ No Occurence ~~~~~~~~~~~~~~*" << std::endl;
	{
		std::list<int>	haystack(100, 7);

		easyfind(haystack, needle);
	}

	std::cout << "\n*~~~~~~~~~~~~~~ With Occurence ~~~~~~~~~~~~~~*" << std::endl;
	{
		std::list<int>	haystack;

		haystack.push_back(1);
		haystack.push_back(2);
		haystack.push_back(42);
		haystack.push_back(3);
		easyfind(haystack, needle);
	}
	return (0);
}