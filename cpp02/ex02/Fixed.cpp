#include "Fixed.hpp"

int const	Fixed::_bits = 8;

Fixed::Fixed( void ) : _nb(0) {
	return;
}

Fixed::Fixed( Fixed const &f ) : _nb(f._nb) {
	*this = f;
	return;
}

Fixed::Fixed( int const toconvert ) {
	this->_nb = roundf(toconvert * (1 << Fixed::_bits));
}

Fixed::Fixed( float const toconvertf ) {
	this->_nb = roundf(toconvertf * (1 << Fixed::_bits));
}

Fixed	&Fixed::operator=( Fixed const &rhs) {
	this->_nb = rhs.getRawBits();
	return *this;
}

std::ostream	&operator<<(  std::ostream &o, Fixed const &src ) {
	o << src.toFloat();
	return o;
}

//Comparaison
bool	Fixed::operator==( Fixed const &rhs ) const {
	if (this->getRawBits() == rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=( Fixed const &rhs ) const {
	return !(this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator< ( Fixed const &rhs ) const {
	if (this->getRawBits() < rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator> ( Fixed const &rhs ) const {
	return rhs.getRawBits() < this->getRawBits();
}

bool	Fixed::operator<=( Fixed const &rhs ) const {
	return !(this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator>=( Fixed const &rhs ) const {
	return !(this->getRawBits() < rhs.getRawBits());
}

//Arithmétique
Fixed	Fixed::operator+( Fixed const &rhs ) {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-( Fixed const &rhs ) {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*( Fixed const &rhs ) {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const &rhs ) {
	return Fixed(this->toFloat() / rhs.toFloat());
}

//Incrémentation
Fixed	&Fixed::operator++( void ) {
	this->_nb = this->_nb + 1.0f;
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed old = *this;

	operator++();
	return old;
}

Fixed	&Fixed::operator--( void ) {
	this->_nb = this->_nb - 1.0f;
	return *this;
}

Fixed	Fixed::operator--( int ) {
	Fixed old = *this;

	operator--();
	return old;
}

//Fonctions
int		Fixed::getRawBits( void ) const {
	return this->_nb;
}

void	Fixed::setRawBits( int const raw ) {
	this->_nb = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_nb / (float)(1 << this->_bits));
}

int		Fixed::toInt( void ) const {
	return (this->_nb >> this->_bits);
}

//Fonctions surchargées
Fixed	&Fixed::min( Fixed &nb_1, Fixed &nb_2 ) {
	if (nb_1 < nb_2)
		return nb_1;
	return nb_2;
}

Fixed const	&Fixed::min( Fixed const &nb_1, Fixed const &nb_2 ) {
	if (nb_1 < nb_2)
		return nb_1;
	return nb_2;
}

Fixed	&Fixed::max( Fixed &nb_1, Fixed &nb_2 ) {
	if (nb_1 > nb_2)
		return nb_1;
	return nb_2;
}

Fixed const	&Fixed::max( Fixed const &nb_1, Fixed const &nb_2 ) {
	if (nb_1 > nb_2)
		return nb_1;
	return nb_2;
}

Fixed::~Fixed( void ) {
	return;
}