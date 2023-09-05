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

	if (name.compare("ShrubberyCreation") == 0)
	{
		form = new ShrubberyCreationForm(target);
		std::cout << "Intern creates " << form->getName() << std::endl;
	}
	else if (name.compare("RobotomyRequest") == 0)
	{
		form = new RobotomyRequestForm(target);
		std::cout << "Intern creates " << form->getName() << std::endl;
	}
	else if (name.compare("PresidentialPardon") == 0)
	{
		form = new PresidentialPardonForm(target);
		std::cout << "Intern creates " << form->getName() << std::endl;
	}
	else
		std::cout << "No form matches the given name" << std::endl;
	return form;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
	return;
}