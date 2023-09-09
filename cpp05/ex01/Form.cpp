/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:24:50 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:24:52 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("Undefined"), _signed(false), _signgrade(150), _execgrade(150) {
	std::cout << "Form Default constructor called" << std::endl;
	return;
}

Form::Form( Form const &src ) : _name(src.getName()), _signed(src.getSignedStatus()), _signgrade(src.getSignGrade()), _execgrade(src.getExecGrade()) {
	std::cout << "Form Copy constructor called" << std::endl;
	return;
}

Form::Form( std::string const name, int const signgrade, int const execgrade ) : _name(name), _signed(false), _signgrade(signgrade), _execgrade(execgrade) {
	if (signgrade < 1 || execgrade < 1)
		throw GradeTooHighException();
	if (signgrade > 150 || execgrade > 150)
		throw GradeTooLowException();
	return;
}

Form	&Form::operator=( Form const &rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.getSignedStatus();
	}
	return *this;
}

std::ostream	&operator<<( std::ostream &o, Form const &F )
{
	o << "Name : " << F.getName() << std::endl << "Signed status : " << F.getSignedStatus() << std::endl << "Sign Grade : " << F.getSignGrade() << std::endl << "Exec Grade : " << F.getExecGrade() << std::endl;
	return o;
}

std::string const	Form::getName( void ) const {
	return this->_name;
}

bool	Form::getSignedStatus( void ) const {
	return this->_signed;
}

int	Form::getSignGrade( void ) const {
	return this->_signgrade;
}

int	Form::getExecGrade( void ) const {
	return this->_execgrade;
}

void	Form::beSigned( Bureaucrat const &B ) {
	if (B.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->_signed = true;
	return;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
	return;
}
