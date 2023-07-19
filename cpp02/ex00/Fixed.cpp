#include "Fixed.hpp"

int const	Fixed::_bits = 8;

Fixed::Fixed( void ) : _nb(0) {
	std::cout << "Default Constructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const &f ) : _nb(f._nb) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
	return;
}

Fixed	&Fixed::operator=( Fixed const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_nb = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_nb;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_nb = raw;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}