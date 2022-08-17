#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "colors.hpp"
# include "Contact.hpp"

class PhoneBook {

	private:
		Contact	_contact[8];

		void	prompt(void) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void) const;

};

#endif