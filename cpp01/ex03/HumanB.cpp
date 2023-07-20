#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	_weap = NULL;
}

HumanB::~HumanB() {
}

std::string HumanB::getName() const {
	return this->_name;
}

void	HumanB::setWeapon(Weapon &weap) {
	this->_weap = &weap;
}

void	HumanB::attack(void) const {
	if (!_weap)
		std::cout << this->_name << " has no weapon and can't attack " << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weap->getType() << std::endl;
}