/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:05:54 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:05:58 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _Name("DEFAULT"), _Hit_Points(10), _Energy_Points(10), _Attack_Damage(0) {
	std::cout << "ClapTrap " << this->_Name << " is created by default" << std::endl;
	return;
}

ClapTrap::ClapTrap( std::string const name ) : _Name(name), _Hit_Points(10), _Energy_Points(10), _Attack_Damage(0) {
	std::cout << "ClapTrap " << this->_Name << " is created by parameter" << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const &src ) : _Name(src._Name), _Hit_Points(src._Hit_Points), _Energy_Points(src._Energy_Points), _Attack_Damage(src._Attack_Damage) {
	std::cout << "ClapTrap " << this->_Name << " is created by copy" << std::endl;
	return;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const &rhs ) {
	if (this != &rhs)
	{
		this->_Name = rhs.getName();
		this->_Hit_Points = rhs.getHitPoints();
		this->_Energy_Points = rhs.getEnergyPoints();
		this->_Attack_Damage = rhs.getAttackDamage();
	}
	return *this;
}

void	ClapTrap::attack( const std::string &target ) {
	if (this->_Hit_Points == 0)
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
	if (this->_Hit_Points == 0)
		std::cout << "ClapTrap " << this->_Name << " is already out of Hit Points, you should stop attacking" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_Name << " takes " << amount << " points of damage :(" << std::endl;
		if (this->_Hit_Points < amount)
			this->_Hit_Points = 0;
		else
			this->_Hit_Points = this->_Hit_Points - amount;
	}
	return;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_Hit_Points == 0)
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

std::string	ClapTrap::getName( void ) const {
	return this->_Name;
}

unsigned int	ClapTrap::getHitPoints( void ) const {
	return this->_Hit_Points;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const {
	return this->_Energy_Points;
}

unsigned int	ClapTrap::getAttackDamage( void ) const {
	return this->_Attack_Damage;
}

void	ClapTrap::setName(std::string const name) {
	this->_Name = name;
	return;
}

void	ClapTrap::setHitPoints(unsigned int hp) {
	this->_Hit_Points = hp;
	return;
}

void	ClapTrap::setEnergyPoints(unsigned int ep) {
	this->_Energy_Points = ep;
	return;
}

void	ClapTrap::setAttackDamage(unsigned int ad) {
	this->_Attack_Damage = ad;
	return;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << this->_Name << " is destroyed" << std::endl;
	return;
}
