#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_RawBits; // value of fixed number
		static int const	_nBits;

	public:
		Fixed(); 					// default constructor
		Fixed(int const value); 	// parametric constructor
		Fixed(float const value); 	// parametric constructor
		Fixed(Fixed const & src);	// copy constructor
		~Fixed();					// destructor

		Fixed &	operator=(Fixed const &rhs); 	// assignment operator overload

		// comparison operators overload
		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;
		// arithmetic operators overload
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;
		// de/incrementation operators overload
		Fixed & operator++();       	// Prefix increment operator  
    	Fixed	operator++(int);     	// Postfix increment operator
		Fixed & operator--();       	// Prefix decrement operator  
    	Fixed	operator--(int);     	// Postfix decrement operator

		int		getRawBits(void) const;
		void 	setRawBits(int const raw);

		float	toFloat(void) const;
		int 	toInt(void) const;

};

std::ostream & operator<<(std::ostream &o, Fixed const &src);

#endif
