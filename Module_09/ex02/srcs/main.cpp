#include "PmergeMe.hpp"

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Correct usage ./PmergeMe < positive integer sequence>" << std::endl;
		return (FAILURE);
	}

	PmergeMe	myPmerge;
	// link : https://stackoverflow.com/questions/26478139/properly-combining-merge-sort-and-insertion-sort-in-c
	return (SUCCESS);
}