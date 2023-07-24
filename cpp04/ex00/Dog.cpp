#include "Dog.hpp"

Dog::Dog( void ) : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	return;
}

Dog::Dog( Dog const &src ) : Animal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = src.getType();
	return;
}

void	Dog::makeSound() const {
	std::cout << "woof" << std::endl;
	return;
}

Dog	&Dog::operator=( Dog const &rhs ) {
	if (this != &rhs)
		this->_type = this->getType();
	return *this;
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	return;
}