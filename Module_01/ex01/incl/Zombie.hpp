#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	_Name;

	public:
		Zombie();
		~Zombie();

		void	setName(std::string name);
		void	announce(void) const;

};


#endif