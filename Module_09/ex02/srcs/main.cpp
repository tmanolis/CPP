#include "PmergeMe.hpp"

/**
 * @brief Check that args are positives integers
 * 
 * How to avoid overflow when we convert a string to an integer :
 * 
 * long	strtol(const char* str, char** endptr, int base);
 * - str : C-string to convert
 * - endptr : Set this pointer to the first character that could not be converted. 
 * 		=> If the entire string can be converted to a long integer, the pointer will be set to point to the null character at the end of the string.
 * - base : Numerical base (radix) that determines the valid characters and their interpretation.
 * - the strtol function returns a long value.
 * 
 * @param endptr : To check if the entire string was converted successfully,
 * We can compare the endptr pointer to the address of the null character at the end of the string :
 * 	=> Adding the length of the string to the starting address of the string, which gives us a pointer to the null character.
 * 
 */
bool	checkArgsAreValid(char **argv)
{
	char	*str;
	char	*endptr;
	long 	value;

	for (int i = 1; argv[i]; i++)
	{
		str = argv[i];
		value = std::strtol(str, &endptr, 10);  	// convert to long
	
		if (value > INT_MAX || endptr != str + std::strlen(str))	// Check that endptr point to the same address that the the of str;
		{
			std::cerr << "Error: " << str << " is greater than INT_MAX" << std::endl;
			return (false);
		}
		if (value < 0)
		{
			std::cerr << "Error: " << str << " is not a positive integer" << std::endl;
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
	if (checkArgsAreValid(argv) == false)
		return (FAILURE);
		
	// PmergeMe	myPmerge(argv);
	// link : https://stackoverflow.com/questions/26478139/properly-combining-merge-sort-and-insertion-sort-in-c
	return (SUCCESS);
}