#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::~Zombie() {
	std::cout << this->_name << " is destroyed" << std::endl;
	return;
}

void	Zombie::announce(void) const {
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName() const {
	return this->_name;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}