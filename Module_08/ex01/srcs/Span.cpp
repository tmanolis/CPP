#include "Span.hpp"

/* Constructors & Destructor */

Span::Span() : _range (0)
{
	std::cout << "[Span] Default Constructor called" << std::endl;
}

Span::Span(Span const &src)
{
	std::cout << "[Span] Copy Constructor called" << std::endl;
	*this = src;
}

Span::~Span()
{
	std::cout << "[Span] Destructor called" << std::endl;
}

Span::Span(unsigned int range) : _range(range)
{
	std::cout << "[Span] Parametric Constructor called" << std::endl;
}

/* Operator Overload */

Span const & Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_span.clear();
		this->_span = rhs.getSpan();
		this->_range = rhs.getRange();
	}
	return (*this);
}

/* Accessors */

std::vector<int>	Span::getSpan() const
{
	return (this->_span);
}

unsigned int		Span::getRange() const
{
	return (this->_range);
}

/* Public Member Functions */
void	Span::addNumber(int const number)
{
	if (this->_span.size() < this->_range)
		this->_span.push_back(number);
	else
		throw SpanFullException();
}

void	Span::addPlageNumber(unsigned int plage)
{
	srand(time(NULL));
	
	for (unsigned int i = 0; i < plage; i++)
			this->addNumber((rand() % 10000) + 1);	
}

/**
 * @brief std::sort
 * template <class RandomAccessIterator>  void sort (RandomAccessIterator first, RandomAccessIterator last);
 * 
 * Sorts the elements in the range [first,last) into ascending order.
 */

unsigned int	Span::shortestSpan() const
{
	// Check if their is enought element in a span to compare
	if (this->_span.empty() == true || this->_span.size() == 1)
			throw SizeErrorException();
	
	// Sort and compare difference between each element to find the shortest
	unsigned int				shortest_span = UINT_MAX;
	std::vector<int> 			tmp = this->_span;
	std::vector<int>::iterator	it = tmp.begin();
	std::vector<int>::iterator	last = tmp.end();

	std::sort(it, last);
	while (it + 1 != last)
	{
		unsigned int	diff = *(it + 1) - *it;
		if (diff < shortest_span)
			shortest_span = diff;
		it++;
	}

	return (shortest_span);
}

unsigned int	Span::longestSpan() const
{
	if (this->_span.empty() == true || this->_span.size() == 1)
			throw SizeErrorException();
	
	std::vector<int> 			tmp = this->_span;
	std::vector<int>::iterator	first = tmp.begin();
	std::vector<int>::iterator	last = tmp.end();

	std::sort(first, last);

	return (*(last - 1) - *first);
}

void			Span::displaySpan() const
{
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	last = this->_span.end();

	std::cout << UCYN << "Span number:" << RESET << std::endl;
	for (it = this->_span.begin(); it != last; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/* Exceptions */

char const * Span::SpanFullException::what() const throw()
{
	return ("Span is full, can't add another number");
}

char const * Span::SizeErrorException::what() const throw()
{
	return ("Span size is empty or has not enough element to compare");
}
