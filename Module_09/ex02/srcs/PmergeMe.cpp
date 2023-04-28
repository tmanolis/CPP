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
		_Mydeque.push_back(value);
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

bool	PmergeMe::isSorted() const
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
template <typename T>
static void	insertSort(T &container)
{
	
	for(std::size_t j = 1; j < container.size(); j++)
    {
      int key = container[j];
      int i = j-1;

      while(i >= 0 && container[i] > key)
      {
         container[i+1] = container[i];
         i--;
      } 
      container[i+1] = key;
    }
}

template <typename T>
static void	mergeHalves(T leftHalf, T rightHalf, T &container)
{
	T	sorted;

	// Merge the halves : store l'élément le plus petit dans le temp vector sorted
	while (leftHalf.empty() == false && rightHalf.empty() == false)
	{
		if (leftHalf.front() <= rightHalf.front())
		{
			sorted.push_back(leftHalf.front()); // on push la valeur la plus petite
			leftHalf.erase(leftHalf.begin()); // on l'efface du sub array
		}
		else
		{
			sorted.push_back(rightHalf.front());
			rightHalf.erase(rightHalf.begin());
		}
	}

	// Insert all the remaining values into the vector sorted
	while (leftHalf.empty() == false)
	{
		sorted.push_back(leftHalf.front());
		leftHalf.erase(leftHalf.begin());
	}

	while (rightHalf.empty() == false)
	{
		sorted.push_back(rightHalf.front());
		rightHalf.erase(rightHalf.begin());
	}
	container = sorted;
}

/* 
Useful link : https://www.codingninjas.com/codestudio/library/sorting-by-combining-insertion-sort-and-merge-sort-algorithms
*/
template <typename T>
static void	merge_insertSort(T &container)
{
	T	leftHalf;
	T	rightHalf;

	if (container.size() <= 1)
		return ;
	if (container.size() <= THRESHOLD)
		return (insertSort(container));

	// Finding the middle point to divide the vector into two halves
	leftHalf.assign(container.begin(), container.begin() + container.size()/2);
	rightHalf.assign(container.begin() + container.size() / 2, container.end());

	// Calling merge_insertSort for the first half and second half
	merge_insertSort(leftHalf);
	merge_insertSort(rightHalf);

	// Merge the two halves sorted in the above steps
	mergeHalves(leftHalf, rightHalf, container);
}

void	PmergeMe::sort(double &time_JohnVector, double &time_KristyList)
{
	// Vector
	clock_t start_time = clock(); // Start time
	merge_insertSort(_John_vector);
	clock_t end_time = clock(); // End time
	time_JohnVector = (double)(end_time - start_time) / ((double)CLOCKS_PER_SEC/1000000); // Time taken in microseconds
	
	// Deque
	start_time = clock();
	merge_insertSort(_Mydeque);
	end_time = clock();
	time_KristyList = (double)(end_time - start_time) / ((double)CLOCKS_PER_SEC/1000000);
	std::cout << "\nDque: ";
	for (size_t i = 0; i < _Mydeque.size(); i++)
		std::cout << _Mydeque[i] << " ";
}