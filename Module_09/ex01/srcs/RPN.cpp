#include "RPN.hpp"

/* Constructors & Destructor */

RPN::RPN()
{
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN()
{
}

/* Accessors */

std::stack<int>	RPN::getMystack() const
{
	return (this->_mystack);
}

/* Member functions */

void	RPN::resolve(std::string str)
{
	for (std::string::iterator it = str.begin(); it!=str.end(); it++)
	{
		int	nb;
		if (std::iswspace(*it) == true)
			it++;
		if (std::isdigit(*it) == true)
		{
			nb = *it - '0'; // convert ascii value for a single digit number into the right integer value
			_mystack.push(nb);
		}
		else
		{
			// if != "+ - / *"
			// {
				// throw std::runtime_error("");
			// 	std::cerr << *it << " is not a valid input" << std::endl;
			// 	return (FAILURE);
			// }
			
		}
	}

}