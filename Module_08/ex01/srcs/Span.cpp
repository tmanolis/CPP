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
	try
	{
		if (this->_span.size() < this->_range)
			this->_span.push_back(number);
		else
			throw SpanFullException();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void	Span::addMaxRange()
{
	srand(time(NULL));
	size_t	size = this->_span.size();
	try
	{
		if (size < this->_range)
		{
			for (unsigned int i = size; i < this->_range; i++)
				this->addNumber(rand() % this->_range);	
		}
		else
			throw SpanFullException();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
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
			shortest_span = (it + 1) - it;
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
