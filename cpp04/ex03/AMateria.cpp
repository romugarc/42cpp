#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("No-type") {
	//std::cout << "AMateria default constructor called" << std::endl;
	return;
}

AMateria::AMateria( const AMateria &src ) : _type(src._type) {
	//std::cout << "AMateria copy constructor called" << std::endl;
	return;
}

AMateria::AMateria( std::string const &type ) : _type(type) {
	//std::cout << "AMateria type constructor called" << std::endl;
	return;
}

const std::string	&AMateria::getType ( void ) const {
	return this->_type;
}

void	AMateria::use( ICharacter &target ) {
	std::cout << "No-type: \"*used a blunt materia on " << target.getName() << " *\"" << std::endl;
}

AMateria	&AMateria::operator=( AMateria const &rhs ) {
	if ( this != &rhs )
		this->_type = rhs.getType();
	return *this;
}

AMateria::~AMateria( void ) {
	//std::cout << "AMateria destructor called" << std::endl;
	return;
}