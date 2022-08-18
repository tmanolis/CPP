#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "colors.hpp"

std::string	get_input(void);
void		print_formated_info(std::string str);

class Contact {
	
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNumber;
		std::string	_DarkestSecret;
	
	public:
		Contact(void);
		~Contact(void);

		std::string	get_FirstName(void) const;

		void		FillContact(void);
		void		PrintContact(int i) const;
		void		PrintContactDetails(void) const;
		
		static int	nb_Contacts;
};

#endif