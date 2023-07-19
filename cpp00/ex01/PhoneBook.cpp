#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
	return;
}

void	PhoneBook::add_contact(int i) {
	this->_contact[i].setFirstName();
	this->_contact[i].setLastName();
	this->_contact[i].setNickname();
	this->_contact[i].setPhoneNumber();
	this->_contact[i].setDarkestSecret();
}

void	PhoneBook::display_contact(int i) const {
	std::cout << "First Name: " << this->_contact[i].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_contact[i].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contact[i].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->_contact[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contact[i].getDarkestSecret() << std::endl;
}

bool	PhoneBook::is_contact(int i) const {
	if (this->_contact[i].getFirstName().empty() == true)
		return (false);
	return (true);
}

void	PhoneBook::display_existing_contact(int i) const {
	int	size;

	std::cout << std::setw(10) << i << '|';
	size = this->_contact[i].getFirstName().size();
	if (size > 10)
		this->_contact[i].display_ten_char(this->_contact[i].getFirstName());
	else
		std::cout << std::setw(10) << this->_contact[i].getFirstName() << '|';
	size = this->_contact[i].getLastName().size();
	if (size > 10)
		this->_contact[i].display_ten_char(this->_contact[i].getLastName());
	else
		std::cout << std::setw(10) << this->_contact[i].getLastName() << '|';
	size = this->_contact[i].getNickname().size();
	if (size > 10)
		this->_contact[i].display_ten_char(this->_contact[i].getNickname());
	else
		std::cout << std::setw(10) << this->_contact[i].getNickname() << '|';
	std::cout << std::endl;
}