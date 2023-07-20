#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "ScavTrap " << this->getName() << " is created by default" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	return;
}

ScavTrap::ScavTrap( std::string const name) : ClapTrap(name) {
	std::cout << "ScavTrap " << this->getName() << " is created by parameter" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	return;
}

ScavTrap::ScavTrap( ScavTrap const &src ) : ClapTrap(src) {
	*this = src;
	std::cout << "ScavTrap " << this->getName() << " is created by copy" << std::endl;
	return;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const &rhs ) {
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return *this;
}

void	ScavTrap::attack( const std::string &target ) {
	if (this->getHitPoints() == 0)
		std::cout << "ScavTrap " << this->getName() << " is out of Hit Points and can't attack...." << std::endl;
	else if (this->getEnergyPoints() == 0)
		std::cout << "ScavpTrap " << this->getName() << " is out of Energy Points and can't attack...." << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	return;
}

void	ScavTrap::guardGate( void ) {
	if (this->getHitPoints() == 0)
		std::cout << "ScavTrap " << this->getName() << " is out of Hit Points and can't guard...." << std::endl;
	else if (this->getEnergyPoints() == 0)
		std::cout << "ScavpTrap " << this->getName() << " is out of Energy Points and can't guard...." << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->getName() << " enters Gate Keeper mode" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	return;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << this->getName() << " is destroyed" << std::endl;
	return;
}