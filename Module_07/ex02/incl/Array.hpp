#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;
		
	public:
		Array();						// Default Constructor
		Array(Array<T> const &src);		// Copy Constructor
		~Array();						// Destructor

		Array(unsigned int n);			// Parametric Constructor

		// Operators overload
		Array<T> & operator=(Array<T> const &rhs);
		T & operator[](unsigned int index);


		// Accessors
		unsigned int	size() const;
		T				*getArray() const;

		// Exceptions
		class	IndexOutOfRangeException : public std::exception 
		{
			virtual char const *	what() const throw();
		};
};

template<typename T>
std::ostream & operator<<(std::ostream &o, Array<T> const &rhs)
{
	for (unsigned int i = 0; i < rhs.size(); i++)
		o << "[" << i << "] = " << rhs.getArray()[i] << std::endl;
	
	return (o);
}


/* Constructors & Destructor */

template<typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	std::cout << "[Array] Default Constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(Array<T> const &src) 
{
	std::cout << "[Array] Copy Constructor called" << std::endl;
	
	// deep copy
	this->_array = new T[src._size];
	this->_size = src._size;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "[Array] Destructor called" << std::endl;
	if (this->_size > 0)
		delete [] this->_array;
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << "[Array] Parametric Constructor called" << std::endl;
	this->_array = new T[n];
}

/* Operator Overload */

template<typename T>
Array<T> &	Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		if (this->_array)
			delete [] this->_array;
		this->_array = new T[rhs.size()];
		
		this->_size = rhs.size();
		
		for (int i = 0; i < this->_size; ++i)
			this->_array[i] = rhs[i];
	}
	return (*this);
}

template<typename T>
T & Array<T>::operator[](unsigned int index)
{
	if (index >= (this->_size))
		throw IndexOutOfRangeException();
	else
		return (this->_array[index]);
}

/* Accessors */

template<typename T>
unsigned int	Array<T>::size() const
{
	return (this->_size);
}

template<typename T>
T *	Array<T>::getArray() const
{
	return (this->_array);
}

/* Exceptions */

template<typename T>
char const * Array<T>::IndexOutOfRangeException::what() const throw()
{
	return ("unvalid index used, out of array size");
}

#endif