#include "Weapon.hpp"

Weapon::Weapon(std::string arme) : _type(arme) {
}

Weapon::~Weapon() {
}

std::string const & Weapon::getType() const {
	return this->_type;
}

void	Weapon::setType(std::string newtype) {
	this->_type = newtype;
}
