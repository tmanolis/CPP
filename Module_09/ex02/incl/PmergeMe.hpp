#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define SUCCESS 0
# define FAILURE -1

#define THRESHOLD 7
// Useful link : https://stackoverflow.com/questions/47945589/why-is-insertion-sort-on2-better-at-sorting-small-array-7-elements-compare

# include <iostream>
# include <cstdlib>
# include <climits>
# include <sstream>
# include <vector>
# include <deque>

# include <unistd.h>

class PmergeMe
{
	private:
		std::vector<int>	_JohnVector;
		std::deque<int>		_LanaDeque;
		
	public:
		PmergeMe();							// Default Constructor
		PmergeMe(PmergeMe const & src);		// Copy Constructor
		~PmergeMe();						// Destructor
		
		PmergeMe(char **argv);				// Parametric Constructor
		// Operator Overload
		PmergeMe & operator=( PmergeMe const & rhs );
		// Accessors
		std::vector<int>	GetJohnVector() const;
		std::deque<int>		GetLanaDeque() const;
		// Member functions
		bool	isSorted() const;
		double	sortJohnVector();
		double	sortLanaDeque();
};

#endif