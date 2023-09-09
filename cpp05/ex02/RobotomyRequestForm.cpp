/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:27:05 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:27:06 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), _target("Nothing") {
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src ) : AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget()) {
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	setSignedStatus(src.getSignedStatus());
	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm Parametrized constructor called" << std::endl;
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs ) {
	(void)rhs;
	return *this;
}

std::string const	RobotomyRequestForm::getTarget( void ) const {
	return this->_target;
}

void	RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
	this->CheckExec(executor);
	std::cout << "VRRR... VRR..VRR.. VRRRRRRRRRRRRRRRR" << std::endl;
	std::cout << "Tiens toi bien ça va bien se passer" << std::endl;
	if (std::rand() % 2 == 1)
		std::cout << "Robotomisation réussie sur " << executor.getName() << " ! Gnark gnark gnark" << std::endl;
	else
		std::cout << "Oups ! Encore un autre de cassé" << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return;
}
