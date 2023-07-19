#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
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
	std::cout << this->_name << " attacks with their " << this->_weap->getType() << std::endl;
}