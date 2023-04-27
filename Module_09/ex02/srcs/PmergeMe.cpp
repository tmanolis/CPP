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

bool	PmergeMe::isSorted()
{
	if (_John_vector.size() <= 1)
		return (true);

	for (size_t i = 0; i < _John_vector.size() - 1; i++)
	{
		if (_John_vector[i] > _John_vector[i + 1])
			return (false);
	}
	return (true);
}

// #########################################
// #				VECTOR			       #
// #########################################

/*
Useful link : Useful link : https://programmercave0.github.io/blog/2017/08/20/C++-Insertion-Sort-using-STL-(Sorting)
*/
static double	insertSort(std::vector<int> &vec)
{
	clock_t start_time = clock();
	
	for(std::size_t j = 1; j < vec.size(); j++)
    {
      int key = vec[j];
      int i = j-1;

      while(i >= 0 && vec[i] > key)
      {
         vec[i+1] = vec[i];
         i--;
      } 
      vec[i+1] = key;
    }

	clock_t end_time = clock(); // End time
    return ((double)(end_time - start_time) / ((double)CLOCKS_PER_SEC/1000000));	// Time taken in microseconds
}

// If r > l
//      Finding the middle point to divide the array into two halves:  
//              middle m = l + (r-l)/2
//      Calling mergeSort for the first half:   
//              mergeSort(arr, l, m)
//      Calling mergeSort for the second half:
//              mergeSort(arr, m+1, r)
//      Now, merge the two halves sorted in the above steps:
//              merge(arr, l, m, r)

/* 
Useful link : https://www.codingninjas.com/codestudio/library/sorting-by-combining-insertion-sort-and-merge-sort-algorithms
*/
static void	mergeSort(std::vector<int> &vec)
{
	std::vector<int>	leftHalf;
	std::vector<int>	rightHalf;

	// Finding the middle point to divide the vector into two halves
	leftHalf.assign(vec.begin(), vec.begin() + vec.size()/2);
	// for (size_t i = 0; i < leftHalf.size(); i++)
	// 	std::cout << leftHalf[i] << " ";
	// std::cout << std::endl;
	
	rightHalf.assign(vec.begin() + vec.size() / 2, vec.end());
	// for (size_t i = 0; i < rightHalf.size(); i++)
	// 	std::cout << rightHalf[i] << " ";
	// std::cout << std::endl;

}

double	PmergeMe::sortJohnVector()
{
    if (_John_vector.size() <= THRESHOLD)
		return (insertSort(_John_vector));
	
	clock_t start_time = clock(); // Start time
	mergeSort(_John_vector);
	clock_t end_time = clock(); // End time

    return ((double)(end_time - start_time) / ((double)CLOCKS_PER_SEC/1000000)); // Time taken in microseconds
	
}