#ifndef PMERGEME_HPP

# define PMERGEME_HPP
# include <vector>
# include <list>

class PmergeMe
{
	private:
		std::vector<int>	John_vector;
		std::list<int>		Kristy_list;
		
	public:
		PmergeMe();							// Default Constructor
		PmergeMe(PmergeMe const & src);		// Copy Constructor
		~PmergeMe();						// Destructor
		
		// Operator Overload
		PmergeMe & operator=( PmergeMe const & rhs );
		// Accessors
		std::vector<int>	GetJohnVector() const;
		std::list<int>		GetKristyList() const;
		// Member functions

};

#endif