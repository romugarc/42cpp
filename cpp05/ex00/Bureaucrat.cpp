#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Undefined"), _grade(150) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) : _name(src.getName()), _grade(src.getGrade()) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
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

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
	return;
}