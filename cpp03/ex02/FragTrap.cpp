#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "FragTrap " << this->getName() << " is created by default" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return;
}

FragTrap::FragTrap( std::string const name) : ClapTrap(name) {
	std::cout << "FragTrap " << this->getName() << " is created by parameter" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return;
}

FragTrap::FragTrap( FragTrap const &src ) : ClapTrap(src) {
	*this = src;
	std::cout << "FragTrap " << this->getName() << " is created by copy" << std::endl;
	return;
}

FragTrap	&FragTrap::operator=( FragTrap const &rhs ) {
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return *this;
}

void	FragTrap::highFivesGuys( void ) {
	if (this->getHitPoints() == 0)
		std::cout << "FragTrap " << this->getName() << " is out of Hit Points and can't high five...." << std::endl;
	else if (this->getEnergyPoints() == 0)
		std::cout << "FragTrap " << this->getName() << " is out of Energy Points and can't high five...." << std::endl;
	else
	{
		std::cout << "FragTrap " << this->getName() << " is asking for a High Five ! Dont let it hanging, that would be sad" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << this->getName() << " is destroyed" << std::endl;
	return;
}