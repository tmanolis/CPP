#include "PmergeMe.hpp"

/* Constructors & Destructor */

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const & src) 
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		std::istringstream iss(argv[i]);
        int value;
        iss >> value;

		_John_vector.push_back(value);
		_Kristy_list.push_back(value);
	}
}

/* Operator Overload */

PmergeMe & PmergeMe::operator=( PmergeMe const & rhs )
{
	if (this != &rhs)
	{
		this->_John_vector = rhs.GetJohnVector();
		this->_Kristy_list = rhs.GetKristyList();
	}
	return (*this);
}

/* Accessors */

std::vector<int> PmergeMe::GetJohnVector() const
{
	return (this->_John_vector);
}

std::list<int> PmergeMe::GetKristyList() const
{
	return (this->_Kristy_list);
}

/* Member functions */

// #########################################
// #				VECTOR			       #
// #########################################

double	PmergeMe::sortJohnVector()
{
	clock_t start_time = clock(); // Start time
    // Call the function you want to time
    usleep(10);
    
	clock_t end_time = clock(); // End time

    return ((double)(end_time - start_time) / ((double)CLOCKS_PER_SEC/1000000)); // Time taken in microseconds
	
}