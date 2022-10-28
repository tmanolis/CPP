#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <cstdlib>
# include <cmath>
# include <climits>
# include <iomanip>

typedef enum e_type
{
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE,
	UNVALID
}	t_type;

class Convert
{
	private:
		char	_char;
		int		_int;
		float	_float;
		double	_double;			
		t_type	_type;
		
		// Display Flags
		bool	_isValidInt;
		bool	_isValidChar;
		bool	_isPrintableChar;

	public:
		Convert();									// Default Constructor
		Convert(Convert const &src); 				// Copy Constructor
		 ~Convert();								// Destructor

		Convert & operator=(Convert const &rhs); 	// assignement operator overload

		Convert(char const *str);				// Parametric Constructor


		// Public Member Functions
		//	--- Conversion Functions ---	//
		bool	isChar(char const *str);
		bool	isInt(char const *str);
		bool	isFloat(char const *str);
		bool	isDouble(char const *str);
		//	--- Cast Function ---	//
		void	castIntoTypes();
		//	--- Display Function ---	//
		void	setDisplayFlags();
		void	display() const;
};

#endif