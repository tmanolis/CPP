#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	_Ideas[100];

	public:
		Brain();						// Default contrusctor
		Brain(Brain const &src);		// Copy contrusctor
		~Brain();						// Destructor contrusctor

		Brain & operator=(Brain const &rhs); 	//Assignment operator overload 

		// ACCESSORS
		std::string const	*getIdeas() const;
		void				setIdea(size_t index, std::string arg);
};

#endif