/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:26:39 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:26:41 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat( void );
		Bureaucrat( Bureaucrat const &src );
		Bureaucrat( std::string const name, int grade );
		~Bureaucrat();

		Bureaucrat &operator=( Bureaucrat const &rhs );

		std::string const	getName( void ) const;
		int					getGrade( void ) const;

		void	incrGrade( int i );
		void	decrGrade( int i );
		void	signForm( AForm &form ) const;
		void	executeForm( AForm const &form );

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
};

std::ostream	&operator<<( std::ostream &o, Bureaucrat const &B );

#endif
