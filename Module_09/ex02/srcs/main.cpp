#include "PmergeMe.hpp"

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
	// link : https://stackoverflow.com/questions/26478139/properly-combining-merge-sort-and-insertion-sort-in-c
	// for (int i = 0; i < argc - 1; i++)
	// {
	// 	std::cout << "vector[" << i << "] : " << myPmerge.GetJohnVector()[i] << std::endl;
	// }

    double time_taken_JohnVector = myPmerge.sortJohnVector();
    std::cout << "time in micro sec : " << time_taken_JohnVector << std::endl;
	// print function
	
	return (SUCCESS);
}