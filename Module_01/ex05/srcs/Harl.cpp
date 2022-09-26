#include "Harl.hpp"

// PRIVATE FUNCTIONS
void	Harl::_debug(void) const
{
	std::cout << BWHT << "[ DEBUG ]" << RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void	Harl::_info(void) const
{
	std::cout << BWHT << "[ INFO ]" << RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << BWHT << "[ WARNING ]" << RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void) const
{
	std::cout << BWHT << "[ ERROR ]" << RESET << std::endl;
	std::cout << "This is unacceptable!" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl;
}

// PUBLIC FUNCTIONS
Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::complain(std::string level) const
{
	std::string	str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*f_tab[4])(void) const = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++)
	{
		if (str[i] == level)
		{
			(this->*f_tab[i])();
			return ;
		}	
	}
	std::cout << BWHT << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
}