/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:26:36 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:26:37 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Undefined"), _grade(150) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) : _name(src.getName()), _grade(src.getGrade()) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name(name) {
	std::cout << "Bureaucrat Parametrized constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	return;
}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &rhs ) {
	if ( this != &rhs )
		this->_grade = rhs.getGrade();
	return *this;
}

std::ostream	&operator<<( std::ostream &o, Bureaucrat const &B )
{
	o << B.getName() << ", bureaucrat grade " << B.getGrade();
	return o;
}

std::string const	Bureaucrat::getName( void ) const {
	return this->_name;
}

int	Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

void	Bureaucrat::incrGrade( int i ) {
	if (i < 1)
	{
		std::cout << "increase can't be less than 1, grade is unchanged" << std::endl;
		return;
	}
	if (this->_grade - i < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= i;
	std::cout << this->getName() << " got their grade increased to " << this->getGrade() << std::endl;
	return;
}

void	Bureaucrat::decrGrade( int i ) {
	if (i < 1)
	{
		std::cout << "decrease can't be less than 1, grade is unchanged" << std::endl;
		return;
	}
	if (this->_grade + i > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += i;
	std::cout << this->getName() << " got their grade decreased to " << this->getGrade() << std::endl;
	return;
}

void	Bureaucrat::signForm( AForm &form ) const {
	if (this->getGrade() > form.getSignGrade())
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because its grade is too low" << std::endl;
	form.beSigned(*this);
	std::cout << this->_name << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm( AForm const &form ) {
	if (form.getSignedStatus() == false)
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because it's not signed" << std::endl;
	if (this->getGrade() > form.getExecGrade())
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because grade is too low" << std::endl;
	form.execute(*this);
	std::cout << this->getName() << " executed " << form.getName();
	return;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
	return;
}
