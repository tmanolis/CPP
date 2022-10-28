#include "Data.hpp"

int	main(void)
{
	Data		data;
	uintptr_t	serial; // unsigned integer type capable of holding a pointer to void
	Data		*data_copy;

	data.i = 42;
	data.f = 42.42f;
	data.str = "Salut les nazes";

	std::cout << BWHT << "BEFORE CAST" << RESET << std::endl;
	std::cout << "data.i: " << data.i << std::endl;
	std::cout << "data.f: " << data.f << std::endl;
	std::cout << "data.str: " << data.str << std::endl;
	std::cout << "data address: " << CYAN << &data << RESET << std::endl;

	serial = serialize(&data);
	std::cout << std::endl;

	std::cout << "Serial: " << serial << std::endl;

	data_copy = deserialize(serial);
	std::cout << std::endl;

	std::cout << BWHT << "AFTER CAST" << RESET << std::endl;
	std::cout << "data_copy.i: " << data_copy->i << std::endl;
	std::cout << "data_copy.f: " << data_copy->f << std::endl;
	std::cout << "data_copy.str: " << data_copy->str << std::endl;
	std::cout << "data_copy address: " << CYAN << data_copy << RESET << std::endl;

	return (0);
}
