/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:30:52 by jrinna            #+#    #+#             */
/*   Updated: 2022/10/03 15:23:15 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria() {

	cout << "Cure DEFAULT constructor called" << endl;
	this->_type = "cure";
	return;
}

Cure::Cure( const Cure & src ) : AMateria(src) {

	cout << "Cure COPY constructor called" << endl;
	this->_type = src._type;
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure() {

	cout << "Cure destructor called" << endl;
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	if ( this != &rhs )
	{
		cout << "cure ASSIGNMENT operator called" << endl;
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cure const & C )
{
	o << "Type = " << C.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria*	Cure::clone( void ) const {

	AMateria*	clone = new Cure(*this);
	return(clone);
}

void	Cure::use( ICharacter& target ) {

	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */