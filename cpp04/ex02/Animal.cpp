#include "Animal.hpp"

AAnimal::AAnimal( void ) : _type("AAnimal") {
	std::cout << "AAnimal default constructor called" << std::endl;
	return;
}

AAnimal::AAnimal( AAnimal const &src ) : _type(src.getType()) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	return;
}

std::string AAnimal::getType( void ) const {
	return this->_type;
}

void	AAnimal::makeSound() const {
	std::cout << "*animal sounds*" << std::endl;
	return;
}

AAnimal	&AAnimal::operator=( AAnimal const &rhs ) {
	if (this != &rhs)
		this->_type = this->getType();
	return *this;
}

AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal destructor called" << std::endl;
	return;
}