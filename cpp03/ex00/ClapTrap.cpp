#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string &name ) : _Name(name), _Hit_Points(10), _Energy_Points(10), _Attack_Damage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap &src ) : _Name(src._Name), _Hit_Points(10), _Energy_Points(10), _Attack_Damage(0) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	return;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const &rhs ) {
	this->_Name = rhs._Name;
	this->_Hit_Points = rhs._Hit_Points;
	this->_Energy_Points = rhs._Energy_Points;
	this->_Attack_Damage = rhs._Attack_Damage;
	return *this;
}

void	ClapTrap::attack( const std::string &target ) {
	if (this->_Hit_Points <= 0)
		std::cout << "ClapTrap " << this->_Name << " is out of Hit Points and can't attack...." << std::endl;
	else if (this->_Energy_Points <= 0)
		std::cout << "ClapTrap " << this->_Name << " is out of Energy Points and can't attack...." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_Attack_Damage << " points of damage!" << std::endl;
		this->_Energy_Points = this->_Energy_Points - 1;
	}
	return;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_Hit_Points <= 0)
		std::cout << "ClapTrap " << this->_Name << " is already out of Hit Points, you should stop attacking" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_Name << " takes " << amount << " points of damage :(" << std::endl;
		this->_Hit_Points = this->_Hit_Points - amount;
	}
	return;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_Hit_Points <= 0)
		std::cout << "ClapTrap " << this->_Name << " is out of Hit Points and can't repair itself...." << std::endl;
	else if (this->_Energy_Points <= 0)
		std::cout << "ClapTrap " << this->_Name <<  " is out of Energy Points and can't repair itself...." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_Name << " repairs itself and recovers " << amount << " hit points :D" << std::endl;
		this->_Hit_Points = this->_Hit_Points + amount;
		this->_Energy_Points = this->_Energy_Points - 1;
	}
	return;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap destructor called" << std::endl;
	return;
}