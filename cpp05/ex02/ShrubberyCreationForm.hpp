#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const _target;
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( ShrubberyCreationForm const &src );
		ShrubberyCreationForm( std::string const target );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=( ShrubberyCreationForm const &rhs );

		std::string const	getTarget( void ) const;

		void	execute( Bureaucrat const & executor ) const;

		class FileNotOpenException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("File couldn't be opened");
				}
		};
};

#endif