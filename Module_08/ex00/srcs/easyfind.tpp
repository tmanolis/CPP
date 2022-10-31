// #include "easyfind.hpp"

// char const * NoOccurenceException::what() throw()
// {
// 	return ("There is no occurence");
// }

// /**
//  * @brief std::find
//  * template <class InputIterator, class T>   InputIterator find (InputIterator first, InputIterator last, const T& val);
//  * 
//  * Returns an iterator to the first element in the range [first,last) that compares equal to val. 
//  * If no such element is found, the function returns last.
//  * 
//  * @param occurence : is an iterator 
//  */

// template <typename T>
// typename T::const_iterator	easyfind(T const &haystack, int const needle)
// {
// 	typename T::const_iterator	occurence;

// 	occurence = std::find(haystack.begin(), haystack.end(), needle);
// 	try
// 	{
// 		if (occurence != haystack.end())
// 		{
// 			std::cout << GREEN << "First occurence of " << needle << " was found. " << RESET << std::endl;
// 			std::cout << "Position of this occurence is: " << occurence - haystack.begin() << std::endl;
// 		}
// 		else
// 			throw NoOccurenceException();
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << "for " << needle << RESET << std::endl;
// 	}
	
// 	return (occurence);
// }