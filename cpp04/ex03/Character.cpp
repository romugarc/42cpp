#include "Character.hpp"

Character::Character() : _name("No-name"), _floorsize(0) {
	//std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	this->_floor = new long[1];
	this->_floor[0] = NULL;
	return;
}

Character::Character( Character const &src ) : _name(src.getName()), _floorsize(src.getFloorsize()) {
	//std::cout << " Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	this->_floor = new long[_floorsize];
	for (int i = 0; i < _floorsize; i++)
		this->_floor[i] = NULL;
	*this = src;
	return;
}

Character::Character( const std::string name ) : _name(name), _floorsize(0) {
	//std::cout << "Character type constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_floor = new long[1];
	this->_floor[0] = NULL;
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
				this->_inventory[i] = NULL;
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
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = mat->clone();
				//std::cout << this->getName() << " equips " << mat->getType() << " materia in slot: " << i << std::endl;
				return;
			}
			i++;
		}
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
		while (i < this->_floorsize)
		{
			newfloor[i] = this->_floor[i];
			i++;
		}
		newfloor[i] = long(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
		delete [] this->_floor;
		this->_floorsize += 1;
		this->_floor = newfloor;
	}
	return;
}

Character::~Character() {
	//std::cout << "Character destructor called" << std::endl;
	int	i = 0;
	while (i < 4)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		i++;
	}
	i = 0;
	while (i < this->_floorsize)
	{
		if (this->_floor[i])
		{	
			//std::cout << "Floor slot : " << i << " contains : -" << ((AMateria*)(this->_floor[i]))->getType() << "-";
			delete (AMateria*)this->_floor[i];
		}
		i++;
	}
	delete [] this->_floor;
	return;
}