#include "Ice.hpp"

Ice::Ice( void ) : AMateria() {
	//std::cout << "ice default constructor called" << std::endl;
	this->_type = "ice";
	return;
}

Ice::Ice( Ice const &src ) : AMateria(src) {
	//std::cout << "ice copy constructor called" << std::endl;
	this->_type = "ice";
	return;
}

Ice	&Ice::operator=( Ice const &rhs ) {
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

AMateria	*Ice::clone( void ) const {
	AMateria	*clone = new Ice(*this);
	return clone;
}

void	Ice::use( ICharacter &target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice() {
	//std::cout << "ice destructor called" << std::endl;
	return;
}