/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:27:12 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:27:13 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137), _target("Nothing") {
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src ) : AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget()) {
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm Parametrized constructor called" << std::endl;
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs ) {
	if (this != &rhs)
	{
		setSignedStatus(rhs.getSignedStatus());
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string const	ShrubberyCreationForm::getTarget( void ) const {
	return this->_target;
}

void	ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
	this->CheckExec(executor);
	std::fstream	file ((this->getTarget() + "_shrubbery").c_str(), std::ios::out);
	if (!file.is_open() || file.bad())
		throw FileNotOpenException();
	file << "               .o00o" << std::endl;
	file << "              o000000oo" << std::endl;
    file << "             00000000000o" << std::endl;
    file << "           00000000000000" << std::endl;
    file << "         oooooo  00000000  o88o" << std::endl;
    file << "      ooOOOOOOOoo  ```''  888888" << std::endl;
    file << "    OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
    file << "   oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl;
    file << "   OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl;
    file << "    OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
    file << "      OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
    file << "        OO:F_P:O `QQQ/  /Q'" << std::endl;
    file << "           \\. \\ |  // |" << std::endl;
    file << "           d\\ \\\\|_////" << std::endl;
    file << "           qP| \\ _' `|Ob" << std::endl;
    file << "              \\  / \\  \\Op" << std::endl;
    file << "              |  | O| |" << std::endl;
    file << "      _       /\\. \\_/ /\"" << std::endl;
    file << "       `---__/|_\\   //|  __" << std::endl;
    file << "            `-'  `-'`-'-'" << std::endl;
	file.close();
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return;
}
