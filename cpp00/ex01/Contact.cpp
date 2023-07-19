#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
	return;
}

std::string Contact::getFirstName() const {
	return this->_first_name;
}

std::string Contact::getLastName() const {
	return this->_last_name;
}

std::string Contact::getNickname() const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->_phone_number;
}

std::string Contact::getDarkestSecret() const {
	return this->_darkest_secret;
}

void	Contact::setFirstName() {
	bool	done;

	done = false;
	while (!done)
	{
		std::cout << "Enter first name:";
		std::getline(std::cin, this->_first_name);
		if (this->_first_name.empty() == true)
			std::cout << "Field cannot be empty" << std::endl;
		else if (this->_first_name.find_first_not_of(" ") == std::string::npos)
			std::cout << "Field cannot be empty" << std::endl;
		else if (this->_first_name.find_first_of("\t\n\f\v\r") != std::string::npos)
			std::cout << "Field cannot contain tabs" << std::endl;
		else
			done = true;
	}
}

void	Contact::setLastName() {
	bool	done;

	done = false;
	while (!done)
	{
		std::cout << "Enter last name:";
		std::getline(std::cin, this->_last_name);
		if (this->_last_name.empty() == true)
			std::cout << "Field cannot be empty" << std::endl;
		else if (this->_last_name.find_first_not_of(" ") == std::string::npos)
			std::cout << "Field cannot be empty" << std::endl;
		else if (this->_last_name.find_first_of("\t\n\f\v\r") != std::string::npos)
			std::cout << "Field cannot contain tabs" << std::endl;
		else
			done = true;
	}
}

void	Contact::setNickname() {
	bool	done;

	done = false;
	while (!done)
	{
		std::cout << "Enter nickname:";
		std::getline(std::cin, this->_nickname);
		if (this->_nickname.empty() == true)
			std::cout << "Field cannot be empty" << std::endl;
		else if (this->_nickname.find_first_not_of(" ") == std::string::npos)
			std::cout << "Field cannot be empty" << std::endl;
		else if (this->_nickname.find_first_of("\t\n\f\v\r") != std::string::npos)
			std::cout << "Field cannot contain tabs" << std::endl;
		else
			done = true;
	}
}

void	Contact::setPhoneNumber() {
	bool	done;

	done = false;
	while (!done)
	{
		std::cout << "Enter phone number:";
		std::getline(std::cin, this->_phone_number);
		if (this->_phone_number.empty() == true)
			std::cout << "Field cannot be empty" << std::endl;
		else if (this->_phone_number.find_first_not_of(" ") == std::string::npos)
			std::cout << "Field cannot be empty" << std::endl;
		else if (this->_phone_number.find_first_of("\t\n\f\v\r") != std::string::npos)
			std::cout << "Field cannot contain tabs" << std::endl;
		else
			done = true;
	}
}

void	Contact::setDarkestSecret() {
	bool	done;

	done = false;
	while (!done)
	{
		std::cout << "Enter darkest secret:";
		std::getline(std::cin, this->_darkest_secret);
		if (this->_darkest_secret.empty() == true)
			std::cout << "Field cannot be empty" << std::endl;
		else if (this->_darkest_secret.find_first_not_of(" ") == std::string::npos)
			std::cout << "Field cannot be empty" << std::endl;
		else if (this->_darkest_secret.find_first_of("\t\n\f\v\r") != std::string::npos)
			std::cout << "Field cannot contain tabs" << std::endl;
		else
			done = true;
	}
}

void	Contact::display_ten_char(std::string info) const {
	int	n;

	n = 0;
	while (n < 9)
	{
		std::cout << info[n];
		n++;
	}
	std::cout << ".|";
}