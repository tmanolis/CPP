#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack() {}								
		MutantStack(MutantStack const &src) { *this = src; }
		~MutantStack() {}					
			
		MutantStack<T>& operator=(const MutantStack<T>& rhs) 
		{
			this->c = rhs.c;
			return *this;
		}
			
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
			
		iterator begin(void)
		{
			return (this->c.begin());
		}

		iterator end(void)
		{
			return (this->c.end());
		}

		const_iterator begin(void) const
		{
			return (this->c.begin());
		}

		const_iterator end(void) const
		{
			return (this->c.end());
		}
};

#endif