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

/* Operator Overload */

PmergeMe & PmergeMe::operator=( PmergeMe const & rhs )
{
	if (this != &rhs)
	{
		this->John_vector = rhs.GetJohnVector();
		this->Kristy_list = rhs.GetKristyList();
	}
	return (*this);
}

/* Accessors */

std::vector<int> PmergeMe::GetJohnVector() const
{
	return (this->John_vector);
}

std::list<int> PmergeMe::GetKristyList() const
{
	return (this->Kristy_list);
}

/* Member functions */
