/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:28:52 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:28:53 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5), _target("Nothing") {
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &src ) : AForm("PresidentialPardonForm", 25, 5), _target(src.getTarget()) {
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const target ) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm Parametrized constructor called" << std::endl;
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs ) {
	if (this != &rhs)
	{
		setSignedStatus(rhs.getSignedStatus());
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string const	PresidentialPardonForm::getTarget( void ) const {
	return this->_target;
}

void	PresidentialPardonForm::execute( Bureaucrat const &executor ) const {
	this->CheckExec(executor);
	std::cout << "Moi, Zaphod Beeblebrox, souverain de la galaxie, vous accorde à vous, " << this->getTarget() << " mon pardon." << std::endl;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return;
}
