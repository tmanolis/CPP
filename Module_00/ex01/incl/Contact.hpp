#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

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

		static int	nb_Contacts;
};

#endif