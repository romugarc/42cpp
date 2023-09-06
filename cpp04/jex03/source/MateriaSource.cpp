/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warnora <warnora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:26:15 by jrinna            #+#    #+#             */
/*   Updated: 2023/09/06 07:55:58 by warnora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource() {

	cout << "MateriaSource DEFAULT constructor called" << endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = 0;
	}
	return;
}

MateriaSource::MateriaSource( const MateriaSource & src ) {

	//AMateria*	clone;
	cout << "MateriaSource COPY constructor called" << endl;
	for (int i = 0; i < 4; i++)
	{
		//clone = NULL;
		if (src._inventory[i])
		{
			//clone = src._inventory[i]->clone();
			//this->_inventory[i] = clone;
			this->_inventory[i] = src._inventory[i];
		}
		else
			this->_inventory[i] = 0;
		//delete clone;
	}
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource() {

	cout << "MateriaSource destructor called" << endl;
	int	i = 0;
	while (i < 4)
	{
		delete this->_inventory[i];
		i++;
	}
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		cout << "MateriaSource ASSIGNMENT operator called" << endl;
		for (int i = 0; i < 4; i++)
		{
			this->_inventory[i] = rhs._inventory[i];
		}
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, MateriaSource const & M )
{
	for (int i = 0; i < 4; i++)
	{	
		if (M.getInv(i))
		{
			o << " inventory slot : " << i << " contain -" << M.getInv(i)->getType() << "-";
		}
	}
	o << endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	MateriaSource::learnMateria( AMateria* A ) {

	if (A)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!_inventory[i])
			{
				_inventory[i] = A;
				cout << "the MateriaSource has learn : " << A->getType() << " in slot : " << i << endl;
				return;
			}
		}
		cout << "the MateriaSource was unable to equip : " << A->getType() << " because its inventory was full" << endl;
	}
	return;
}

AMateria*	MateriaSource::createMateria( const string & type ) {

	for (int i = 0; i < 4; i++)
	{
		if (this->getInv(i) && !type.compare(this->getInv(i)->getType()))
		{
			cout << "found a materia matching : " << type << " in slot : " << i << endl;
			return (this->getInv(i)->clone());
		}
	}
	cout << "couldn't found a materia matching : " << type << endl;
	return (NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

AMateria*	MateriaSource::getInv( int i ) const {

	if (i < 4 && i > -1)
		return (this->_inventory[i]);
	return (NULL);
}

/* ************************************************************************** */