#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weap) : _name(name), _weap(weap) {
}

HumanA::~HumanA() {
}

std::string HumanA::getName() const {
	return this->_name;
}

void	HumanA::attack(void) const {
	std::cout << this->_name << " attacks with their " << this->_weap.getType() << std::endl;
}