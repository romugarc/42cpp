/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warnora <warnora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:30:52 by jrinna            #+#    #+#             */
/*   Updated: 2023/09/06 04:40:18 by warnora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria() {

	cout << "ice DEFAULT constructor called" << endl;
	this->_type = "ice";
	return;
}

Ice::Ice( const Ice & src ) : AMateria(src) {

	cout << "ice COPY constructor called" << endl;
	this->_type = src._type;
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice() {

	cout << "ice destructor called" << endl;
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
	{
		cout << "ice ASSIGNMENT operator called" << endl;
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Ice const & I )
{
	o << "Type = " << I.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria*	Ice::clone( void ) const {

	AMateria*	clone = new Ice(*this);
	return(clone);
}

void	Ice::use( ICharacter& target ) {

	cout << "* shoot an ice bolt at " << target.getName() << " *" << endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */