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
		delete this->_inventory[i];
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
	this->_floor = new long[0];
	return;
}

Character	&Character::operator=( Character const &rhs ) {
	if (this != &rhs)
	{
		int	i = 0;
		this->_name = rhs.getName();
		this->_floorsize = rhs.getFloorsize();
		while (i < 4)
		{
			delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = 0;
			i++;
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
	return NULL;
}

void	Character::equip( AMateria *mat ) {
	if (mat)
	{
		int	i = 0;
		while (i < 4)
		{
			if (_inventory[i] == 0)
			{
				_inventory[i] = mat;
				std::cout << this->getName() << " equips " << mat->getType() << " materia in slot: " << i << std::endl;
				return;
			}
			i++;
		}
		delete mat;
	}
	return;
}

void	Character::use( int idx, ICharacter &target ) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		_inventory[idx]->use(target);
	return;
}

void 	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		int	i = 0;
		long *newfloor = new long[this->_floorsize + 1];
		while (i < this->_floorsize - 1)
		{
			newfloor[i] = this->_floor[i];
			i++;
		}
		delete this->_floor;
		this->_floorsize += 1;
		this->_floor[i] = long(this->_inventory[idx]);
		this->_inventory[idx] = 0;
		std::cout << this->getName() << " unequips " << _inventory[idx]->getType() << " materia in slot : " << idx << std::endl;
	}
	return;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	int	i = 0;
	while (i < 4)
	{
		delete this->_inventory[i];
		i++;
	}
	i = 0;
	while (i < this->_floorsize - 1)
	{
		if (this->_floor[i])
			std::cout << "floor slot : " << i << " contain : -" << ((AMateria*)(_floor[i]))->getType() << "-";
		delete (AMateria*)this->_floor[i];
	}
	delete [] this->_floor;
	return;
}