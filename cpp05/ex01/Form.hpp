/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:24:57 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:24:58 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signgrade;
		int const			_execgrade;
	public:
		Form( void );
		Form( Form const &src );
		Form( std::string const name, int const signgrade, int const execgrade );
		~Form();

		Form &operator=( Form const &rhs );

		std::string const	getName( void ) const;
		bool				getSignedStatus( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void	beSigned( Bureaucrat const &B );

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

std::ostream	&operator<<( std::ostream &o, Form const &F );

#endif
