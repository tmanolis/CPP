#include "PmergeMe.hpp"

void	printResult(char **argv, std::vector<int> JohnVector, std::deque<int> LanaDeque, double time_JohnVector, double time_LanaDeque)
{
	std::cout << "Before: ";
	for (int i = 1; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << "\nAfter: ";
	for (size_t i = 0; i < JohnVector.size(); i++)
		std::cout << JohnVector[i] << " ";

	std::cout << "\nTime to process a range of " << JohnVector.size() << " with [std::vector] : " << time_JohnVector << " us" << std::endl;
	std::cout << "Time to process a range of " << LanaDeque.size() << " with [std::deque] : " << time_LanaDeque << " us" << std::endl;
}

/**
 * @brief Check that args are valid positives integers
 * 
 * Using std::istringstream to convert a string to an integer is convenient and error-prone 
 * 	=> it automatically handles many common input errors like trailing whitespace and non-numeric input.
 * 
 * - iss.fail() is a method of the std::istringstream class that checks if the most recent input operation on the istringstream object has failed or not.
 * 	=> If the conversion was not successful :
 *	it means that the input string contains characters that are not valid for an integer or the input string is empty, 
 *	and iss.fail() will return true.
 * 
 */
bool	checkArgsAreValids(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
        std::istringstream iss(argv[i]);
        int value;
        iss >> value;

        if (iss.fail() || value < 0 || value > INT_MAX)
		{
            std::cerr << "Error: " << argv[i] << " is not a valid positive integer." << std::endl;
            return (false);
        }
    }

	return (true);
}

// link : https://stackoverflow.com/questions/26478139/properly-combining-merge-sort-and-insertion-sort-in-c

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Correct usage ./PmergeMe <positive integer sequence>" << std::endl;
		return (FAILURE);
	}
	if (checkArgsAreValids(argv) == false)
		return (FAILURE);

	PmergeMe	myPmerge(argv);
	
	if (myPmerge.isSorted() == true)
	{
		std::cerr << "Error: this sequence is already sorted" << std::endl;
		return (FAILURE);
	}
	
    double time_taken_JohnVector = myPmerge.sortJohnVector();
	double time_taken_LanaDeque = myPmerge.sortLanaDeque();
	printResult(argv, myPmerge.GetJohnVector(), myPmerge.GetLanaDeque(), time_taken_JohnVector, time_taken_LanaDeque);

	return (SUCCESS);
}