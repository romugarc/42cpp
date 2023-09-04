#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = 0;
	}
	return;
}

MateriaSource::MateriaSource( const MateriaSource &src ) {
	//AMateria*	clone;
	std::cout << "MateriaSource copy constructor called" << std::endl;
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

MateriaSource &MateriaSource::operator=( MateriaSource const &rhs ) {
	if ( this != &rhs )
	{
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i];
	}
	return *this;
}

void	MateriaSource::learnMateria( AMateria *mat ) {
	if (mat)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!_inventory[i])
			{
				_inventory[i] = mat;
				std::cout << "the MateriaSource has learn : " << mat->getType() << " in slot : " << i << std::endl;
				return;
			}
		}
		std::cout << "the MateriaSource was unable to equip : " << mat->getType() << " because its inventory was full" << std::endl;
	}
	return;
}

AMateria	*MateriaSource::createMateria( const std::string &type ) {
	for (int i = 0; i < 4; i++)
	{
		if (this->getInventory(i) && !type.compare(this->getInventory(i)->getType()))
		{
			std::cout << "found a materia matching : " << type << " in slot : " << i << std::endl;
			return (this->getInventory(i)->clone());
		}
	}
	std::cout << "couldn't found a materia matching : " << type << std::endl;
	return (NULL);
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	return;
}