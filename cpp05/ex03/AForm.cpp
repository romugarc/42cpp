/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:28:13 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:28:14 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) : _name("Undefined"), _signed(false), _signgrade(150), _execgrade(150) {
	std::cout << "AForm Default constructor called" << std::endl;
	return;
}

AForm::AForm( AForm const &src ) : _name(src.getName()), _signed(false), _signgrade(src.getSignGrade()), _execgrade(src.getExecGrade()) {
	std::cout << "AForm Copy constructor called" << std::endl;
	return;
}

AForm::AForm( std::string const name, int const signgrade, int const execgrade ) : _name(name), _signed(false), _signgrade(signgrade), _execgrade(execgrade) {
	if (signgrade < 1 || execgrade < 1)
		throw GradeTooHighException();
	if (signgrade > 150 || execgrade > 150)
		throw GradeTooLowException();
	return;
}

AForm	&AForm::operator=( AForm const &rhs )
{
	if ( this != &rhs )
	{
		(std::string&)this->_name = rhs.getName();
		this->_signed = rhs.getSignedStatus();
		(int&)this->_signgrade = rhs.getSignGrade();
		(int&)this->_execgrade = rhs.getExecGrade();
	}
	return *this;
}

std::ostream	&operator<<( std::ostream &o, AForm const &F )
{
	o << "Name : " << F.getName() << std::endl << "Signed status : " << F.getSignedStatus() << std::endl << "Sign Grade : " << F.getSignGrade() << std::endl << "Exec Grade : " << F.getExecGrade() << std::endl;
	return o;
}

std::string const	AForm::getName( void ) const {
	return this->_name;
}

bool	AForm::getSignedStatus( void ) const {
	return this->_signed;
}

int	AForm::getSignGrade( void ) const {
	return this->_signgrade;
}

int	AForm::getExecGrade( void ) const {
	return this->_execgrade;
}

void	AForm::setSignedStatus( bool s ) {
	this->_signed = s;
	return;
}

void	AForm::beSigned( Bureaucrat const &B ) {
	if (B.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->_signed = true;
	return;
}

void AForm::CheckExec( Bureaucrat const & executor ) const {
	if (this->getSignedStatus() == false)
		throw UnsignedFormException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	return;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
	return;
}
