#include "Character.hpp"

Character::Character() : _name("No-name"), _floorsize(0) {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
	this->_floor = new long[0];
	return;
}

Character::Character( const Character &src ) : _name(src.getName()), _floorsize(src.getFloorsize()) {
	std::cout << " Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i]; //Check si cette ligne est bien utile dans ce cas pour la copie profonde
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	this->_floor = new long[_floorsize];
	return;
}

Character::Character( const std::string name ) : _name(name), _floorsize(0) {
	std::cout << "Character type constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
	this->_floor = new long[_floorsize];
	return;
}

Character	&Character::operator=( Character const &rhs )
{
	if (this != &rhs)
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

const std::string &Character::getName( void ) const {

	return this->_name;
}

int	Character::getFloorsize( void ) const {

	return this->_floorsize;
}

AMateria	*Character::getInventory( int i ) const {

	if (i >= 0 && i < 4)
		return this->_inventory[i];
	return (NULL);
}

void	Character::equip( AMateria *m ) {
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			if (m)
				std::cout << this->getName() << " has equip : " << m->getType() << " in slot : " << i << std::endl;
			else
				std::cout << this->getName() << " has equip nothing in slot : " << i << std::endl;
			return;
		}
	}
	if (m)
		std::cout << this->getName() << " was unable to equip : " << m->getType() << " because his inventory was full" << std::endl;
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
		std::cout << this->getName() << " has UNequip : " << _inventory[idx]->getType() << " in slot : " << idx << std::endl;
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
				std::cout << "floor slot : " << i << " contain : -" << ((AMateria*)(_floor[i]))->getType() << "-";
			if (i == this->_floorsize - 1)
				std::cout << std::endl; 
		}
		this->_inventory[idx] = 0;
	}
	return;
}

Character::~Character() {

	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	for (int i = 0; i < this->_floorsize; i++)
	{
		if (this->_floor[i])
			std::cout << "floor slot : " << i << " contain : -" << ((AMateria*)(_floor[i]))->getType() << "-";
		delete (AMateria*)this->_floor[i];
	}
	delete this->_floor;
	return;
}