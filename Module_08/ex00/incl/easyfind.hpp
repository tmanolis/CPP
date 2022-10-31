#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>

// Colors
# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define BWHT "\e[1;37m"

class NoOccurenceException : public std::exception
{
	public :
		virtual char const	*what() const throw();
};

template <typename T>
typename T::const_iterator	easyfind(T const &haystack, int const needle);

#include "easyfind.tpp"

#endif