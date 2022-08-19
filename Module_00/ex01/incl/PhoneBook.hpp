#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "colors.hpp"
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

void	shift_contacts(Contact *Contacts);
int		get_index(const Contact *Contact);

class PhoneBook {

	private:
		Contact	_Contact[8];

		void	_prompt(void) const;
		void	_PrintContactsList(void) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		Contact	getContact(int index) const;

		void	add(void);
		void	search(void) const;


};

#endif