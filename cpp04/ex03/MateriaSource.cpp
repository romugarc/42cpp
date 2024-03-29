#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	//std::cout << "MateriaSource default constructor called" << std::endl;
	int	i = 0;
	while (i < 4)
	{
		this->_inventory[i] = NULL;
		i++;
	}
	return;
}

MateriaSource::MateriaSource( const MateriaSource &src ) {
	//std::cout << "MateriaSource copy constructor called" << std::endl;
	int	i = 0;
	while (i < 4)
	{
		this->_inventory[i] = NULL;
		i++;
	}
	*this = src;
	return;
}

MateriaSource &MateriaSource::operator=( MateriaSource const &rhs ) {
	if (this != &rhs)
	{
		int	i = 0;
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

AMateria	*MateriaSource::getInventory( int i ) const {
	if (i >= 0 && i < 4 && this->_inventory[i])
		return this->_inventory[i];
	return NULL;
}


void	MateriaSource::learnMateria( AMateria *mat ) {
	if (mat)
	{
		int	i = 0;
		while (i < 4)
		{
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = mat->clone();
				//std::cout << "MateriaSource has learned to create " << mat->getType() << " in slot : " << i << std::endl;
				return;
			}
			i++;
		}
	}
	return;
}

AMateria	*MateriaSource::createMateria( const std::string &type ) {
	int	i = 0;
	while (i < 4)
	{
		if (this->getInventory(i) && type.compare(this->getInventory(i)->getType()) == 0)
		{
			//std::cout << "Found a materia matching : " << type << " in slot : " << i << std::endl;
			return (this->getInventory(i)->clone());
		}
		i++;
	}
	//std::cout << "Couldn't find a materia matching : " << type << std::endl;
	return (NULL);
}

MateriaSource::~MateriaSource() {
	//std::cout << "MateriaSource destructor called" << std::endl;
	int	i = 0;
	while (i < 4)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		i++;
	}
	return;
}