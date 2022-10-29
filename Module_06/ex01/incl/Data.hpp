#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <cctype>
#include <stdint.h>

// Colors
# define RESET "\e[0m"
# define CYAN "\e[0;36m"
# define BWHT "\e[1;37m"

typedef struct	s_data
{
	int			i;
	float		f;
	std::string	str;
}				Data;

uintptr_t	serialize(Data* ptr);
Data   		*deserialize(uintptr_t raw);

#endif
