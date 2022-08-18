#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include "colors.hpp"

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
		void		PrintContact(void) const;
		void		PrintDetails(void) const;
		
		static int	nb_Contacts;
};

#endif