#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signgrade;
		int	const			_execgrade;
	public:
		AForm( void );
		AForm( AForm const &src );
		AForm( std::string const name, int const signgrade, int const execgrade );
		~AForm();

		AForm &operator=( AForm const &rhs );

		std::string const	getName( void ) const;
		bool				getSignedStatus( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void	setSignedStatus( bool s );
		void	beSigned( Bureaucrat const &B );
		void	CheckExec( Bureaucrat const & executor ) const;
		virtual void	execute( Bureaucrat const & executor) const = 0;

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Grade Too High, should be at least 1");
				}
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Grade Too Low, should be at most 150");
				}
		};

		class	UnsignedFormException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Form is not signed");
				}
		};
};

std::ostream	&operator<<( std::ostream &o, AForm const &F );

#endif