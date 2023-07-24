#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal( WrongAnimal const &src ) : _type(src.getType()) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	return;
}

std::string WrongAnimal::getType( void ) const {
	return this->_type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "*lamina sdnuos*" << std::endl;
	return;
}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const &rhs ) {
	if (this != &rhs)
		this->_type = this->getType();
	return *this;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called" << std::endl;
	return;
}