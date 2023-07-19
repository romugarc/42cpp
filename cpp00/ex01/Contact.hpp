#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class	Contact {
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

	public:
		Contact();
		~Contact();
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		
		void	setFirstName();
		void	setLastName();
		void	setNickname();
		void	setPhoneNumber();
		void	setDarkestSecret();
		
		void	display_ten_char(std::string info) const;
};

#endif