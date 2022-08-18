#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "colors.hpp"
# include "Contact.hpp"

class PhoneBook {

	private:
		Contact	_Contact[8];

		void	_prompt(void) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		Contact	getContact(int index) const;

		void	add(void);
		void	search(void) const;


};

#endif