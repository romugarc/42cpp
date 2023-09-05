#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string const _target;
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( RobotomyRequestForm const &src );
		RobotomyRequestForm( std::string const target );
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=( RobotomyRequestForm const &rhs );

		std::string const	getTarget( void ) const;

		void	execute( Bureaucrat const & executor ) const;
};

#endif