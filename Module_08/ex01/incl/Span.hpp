#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <climits>
# include <algorithm>
# include <vector>

// Colors
# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define BWHT "\e[1;37m"
# define UCYN "\e[4;36m"

class Span
{
	private:
		std::vector<int>		_span;
		unsigned int			_range;

		Span();										// Default Constructor
	
	public:
		Span(Span const &src);						// Copy Constructor
		~Span();									// Destructor

		Span const & operator=(Span const &rhs);	// Assignation operator overload

		Span(unsigned int range);					// Parametric Constructor

		// Accessors
		std::vector<int>	getSpan() const;
		unsigned int		getRange() const;

		// Public member functions
		void			addNumber(int const number);
		void			addPlageNumber(unsigned int plage);
		void			insertRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		void			displaySpan() const;

		// Exceptions
		class SpanFullException : public std::exception
		{
			char const *what() const throw();
		};
		class SizeErrorException : public std::exception
		{
			char const	*what() const throw();
		};

};


#endif
