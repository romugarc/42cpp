#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern( void );
		Intern( Intern const &src );
		~Intern();

		Intern	&operator=( Intern const &rhs );

		AForm	*makeForm( std::string name, std::string target ) const;
};

#endif