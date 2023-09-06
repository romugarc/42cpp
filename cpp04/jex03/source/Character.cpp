/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warnora <warnora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:38:00 by jrinna            #+#    #+#             */
/*   Updated: 2023/09/06 07:56:19 by warnora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : _name("unamed") , _floorsize(0) {

	cout << "DEFAULT character constructor called" << endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
	this->_floor = new long[_floorsize];
	return;
}

Character::Character( const Character & src ) : _name(src.getName()) , _floorsize(src.getFloorsize()) {

	cout << "COPY character constructor called" << endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	this->_floor = new long[_floorsize];
	return;
}

Character::Character( const string name ) : _name(name) , _floorsize(0) {

	cout << "NAMED character constructor called" << endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
	this->_floor = new long[_floorsize];
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character() {

	cout << "character destructor called" << endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
	}
	for (int i = 0; i < this->_floorsize; i++)
	{
		if (this->_floor[i])
			cout << "floor slot : " << i << " contain : -" << ((AMateria*)(_floor[i]))->getType() << "-";
		delete (AMateria*)this->_floor[i];
	}
	delete [] this->_floor;
	
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = 0;
		}
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & C )
{
	o << "Name = " << C.getName() << "||";
	for (int i = 0; i < 4; i++)
	{
		if (C.getInv(i))
		{
			o << " slot : " << i << " contain : -" << C.getInv(i)->getType() << "-" << endl;
		}
	}
	o << endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Character::equip( AMateria* m ) {

	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			if (m)
				cout << this->getName() << " has equip : " << m->getType() << " in slot : " << i << endl;
			else
				cout << this->getName() << " has equip nothing in slot : " << i << endl;
			return;
		}
	}
	if (m)
		cout << this->getName() << " was unable to equip : " << m->getType() << " because his inventory was full" << endl;
	delete m;
	return;
}

void	Character::use( int idx, ICharacter& target ) {

	if (idx > -1 && idx < 4 && this->_inventory[idx])
		_inventory[idx]->use(target);
	return;
}

void 	Character::unequip(int idx) {

	if (idx > -1 && idx < 4 && this->_inventory[idx])
	{
		cout << this->getName() << " has UNequip : " << _inventory[idx]->getType() << " in slot : " << idx << endl;
		long*	newfloor = new long[++this->_floorsize];
		for (long i = 0; i < this->_floorsize - 1; i++)
		{
			newfloor[i] = _floor[i];
		}
		delete this->_floor;
		this->_floor = newfloor;
		this->_floor[this->_floorsize - 1] = long(this->_inventory[idx]);
		for (long i = 0; i < this->_floorsize; i++)
		{
			if (this->_floor[i])
				cout << "floor slot : " << i << " contain : -" << ((AMateria*)(_floor[i]))->getType() << "-";
			if (i == this->_floorsize - 1)
				cout << endl; 
		}
		this->_inventory[idx] = 0;
	}
	return;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const string&	Character::getName( void ) const {

	return (this->_name);
}

int	Character::getFloorsize( void ) const {

	return (this->_floorsize);
}

AMateria*	Character::getInv( int i ) const {

	if (i < 4 && i > -1)
		return (this->_inventory[i]);
	return (NULL);
}

/* ************************************************************************** */