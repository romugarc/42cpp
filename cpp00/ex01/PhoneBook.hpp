#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class	PhoneBook {
	private:
		Contact	_contact[8];
	
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact(int i);
		void	display_contact(int i) const;
		bool	is_contact(int i) const;
		void	display_existing_contact(int i) const;
};

#endif