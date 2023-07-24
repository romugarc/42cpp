#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
	return;
}

Animal::Animal( Animal const &src ) : _type(src.getType()) {
	std::cout << "Animal copy constructor called" << std::endl;
	return;
}

std::string Animal::getType( void ) const {
	return this->_type;
}

void	Animal::makeSound() const {
	std::cout << "*animal sounds*" << std::endl;
	return;
}

Animal	&Animal::operator=( Animal const &rhs ) {
	if (this != &rhs)
		this->_type = this->getType();
	return *this;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
	return;
}