#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string &name) : _Name(name), _Hit_Points(100), _Energy_Points(50), _Attack_Damage(20) {
	std::cout << "ScavTrap constructor called" << std::endl;
	return;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called" << std::endl;
	return;
}