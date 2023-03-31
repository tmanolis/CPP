#ifndef RPN_HPP
#define RPN_HPP

# define SUCCESS 0
# define FAILURE -1

# include <string>
# include <cstdlib>
# include <iostream>
# include <stack>

class RPN
{

	private:
		std::stack<int>	_mystack;

	public:
		RPN();								// Default Constructor
		RPN(RPN const &src);				// Copy Constructor
		~RPN();								// Destructor

	// Accessors
	std::stack<int>	getMystack() const;
	// Member functions
	void			resolve(std::string str);

};


#endif

