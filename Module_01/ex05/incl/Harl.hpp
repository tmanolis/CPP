#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define RESET "\e[0m"
# define BWHT "\e[1;37m"
# define UYEL "\e[4;33m"

class Harl
{
	private:
		void	_debug(void) const;
		void	_info(void) const;
		void	_warning(void) const;
		void	_error(void) const;

	public:
		Harl(/* args */);
		~Harl();

		void    complain(std::string level) const;
};

#endif
