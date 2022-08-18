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

		void	FillContact(void);
		void	PrintDetails(void) const;
		
		static int	nb_Contacts;
};

#endif