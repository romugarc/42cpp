#include "Cure.hpp"

Cure::Cure( void ) : AMateria() {
	//std::cout << "Cure default constructor called" << std::endl;
	this->_type = "cure";
	return;
}

Cure::Cure( Cure const &src ) : AMateria(src) {
	//std::cout << "Cure copy constructor called" << std::endl;
	this->_type = "cure";
	return;
}

Cure	&Cure::operator=( Cure const &rhs ) {
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

AMateria	*Cure::clone( void ) const {

	AMateria	*clone = new Cure(*this);
	return clone;
}

void	Cure::use( ICharacter &target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure() {
	//std::cout << "Cure destructor called" << std::endl;
	return;
}