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
			if (*it != '+' && *it != '-' && *it != '*' && *it != '/')
				throw std::invalid_argument(std::string("Error: ") + *it + " is not a valid input");
			if (_mystack.size() >= 2)
				calculate(*it);
			else
				throw std::invalid_argument("Error: Inverted Polish mathematical expression given is incorrect"); 
		}
	}
}

void	RPN::calculate(char c)
{
	int	a, b, result;

	b = _mystack.top();
	_mystack.pop();
	a = _mystack.top();
	_mystack.pop();

	if (c == '+')
		result = a + b;
	if (c == '-')
		result = a - b;
	if (c == '*')
		result = a * b;
	if (c == '/')
		result = a / b;
	_mystack.push(result);
}
