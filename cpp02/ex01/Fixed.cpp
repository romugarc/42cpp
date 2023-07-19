#include "Fixed.hpp"

int const	Fixed::_bits = 8;

Fixed::Fixed( void ) : _nb(0) {
	std::cout << "Default Constructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::Fixed( int const toconvert ) {
	std::cout << "Int constructor called" << std::endl;
	this->_nb = roundf(toconvert * (1 << Fixed::_bits));
}

Fixed::Fixed( float const toconvertf ) {
	std::cout << "Float constructor called" << std::endl;
	this->_nb = roundf(toconvertf * (1 << Fixed::_bits));
}

Fixed	&Fixed::operator=( Fixed const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_nb = rhs.getRawBits();
	return *this;
}

std::ostream	&operator<<(  std::ostream &o, Fixed const &src ) {
	o << ((float)src.getRawBits() / (float)(1 << 8));
	return o;
}

int		Fixed::getRawBits( void ) const {
	return this->_nb;
}

void	Fixed::setRawBits( int const raw ) {
	this->_nb = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_nb / (float)(1 << 8));
}

int		Fixed::toInt( void ) const {
	return (this->_nb >> this->_bits);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}