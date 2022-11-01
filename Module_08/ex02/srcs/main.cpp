#include "MutantStack.hpp"
#include <list>

// Colors
# define RESET "\e[0m"
# define BWHT "\e[1;37m"
# define UCYN "\e[4;36m"

int main()
{
	std::cout << BWHT<< "================= Stack Test ===============" << RESET << std::endl;
	
	{
		MutantStack<int> mstack;
	
		mstack.push(5);
		mstack.push(17);
		std::cout << "last element added : " << mstack.top() << std::endl; 
		
		mstack.pop();	// remove last element added
		std::cout << "size : " << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << UCYN << "Stack:" << RESET << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		std::stack<int> s(mstack);

		std::cout << "\n*~~~~~~~~~~~~~~ More tests ~~~~~~~~~~~~~~*" << std::endl;
		it = mstack.begin();
		std::cout << "first element added on the stack : " << *it << std::endl;
		it++;
		std::cout << "second element added on the stack : " << *it << std::endl;

	}


	std::cout << BWHT<< "\n================= List Test ===============" << RESET << std::endl;

	{
		std::list<int>	mlist;

		if (mlist.empty())
			std::cout << "empty" << std::endl;
		
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << "last element added : " << mlist.back() << std::endl;
		
		mlist.pop_back();	// remove last element added
		std::cout << "size : " << mlist.size() << std::endl;
		
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		++it;
		--it;
		std::cout << UCYN << "List:" << RESET << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		std::list<int> s(mlist);
	}
	
	return (0);
}