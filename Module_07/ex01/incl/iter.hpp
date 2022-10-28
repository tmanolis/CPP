#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void	iter(T *array, size_t const size, void f(T &array))	// la fonction en 3eme parametre peut aussi s'écrire : void (*ft)(T &) 
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template<typename T>
void	print(T &content)
{
	std::cout << "[" << content << "]" << std::endl;
}

template<typename T>
void	increment(T &content)
{
	content++;
}

#endif 