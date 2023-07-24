#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
	return;
}

WrongCat::WrongCat( WrongCat const &src ) : WrongAnimal(src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->_type = src.getType();
	return;
}

void	WrongCat::makeSound() const {
	std::cout << "weom" << std::endl;
	return;
}

WrongCat	&WrongCat::operator=( WrongCat const &rhs ) {
	if (this != &rhs)
		this->_type = this->getType();
	return *this;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called" << std::endl;
	return;
}