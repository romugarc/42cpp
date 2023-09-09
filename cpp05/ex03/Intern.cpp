/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:28:28 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:28:32 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {
	std::cout << "Intern Default constructor called" << std::endl;
	return;
}

Intern::Intern( Intern const &src ) {
	std::cout << "Intern Copy constructor called" << std::endl;
	(void)src;
	return;
}

Intern	&Intern::operator=( Intern const &rhs) {
	(void)rhs;
	return *this;
}

AForm	*Intern::makeForm( std::string name, std::string target ) const {
	AForm *form = NULL;
	std::string formlist[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	int i = 0;

	while (name != formlist[i] && i++ < 3);

	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "No form matches the name " << name << std::endl;
			break;
	}
	return form;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
	return;
}
