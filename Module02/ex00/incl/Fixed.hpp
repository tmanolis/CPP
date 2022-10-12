#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_RawBits;
		static int const	_nBits;

	public:
		Fixed(); 					// default constructor
		Fixed(Fixed const & src);	// copy constructor 
		~Fixed();					// destructor

		Fixed &	operator=(Fixed const &rhs); // assignment operator overload

		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
};

#endif
