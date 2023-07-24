#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : AWrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
	this->_brain = new Brain();
	return;
}

WrongCat::WrongCat( WrongCat const &src ) : AWrongAnimal(src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->_type = src.getType();
	this->_brain = new Brain(*src.getBrain());
	return;
}

void	WrongCat::makeSound() const {
	std::cout << "weom" << std::endl;
	return;
}

Brain	*WrongCat::getBrain( void ) const {
	return this->_brain;
}

WrongCat	&WrongCat::operator=( WrongCat const &rhs ) {
	if (this != &rhs)
		this->_type = this->getType();
	return *this;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called" << std::endl;
	delete this->_brain;
	return;
}