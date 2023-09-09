/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:28:55 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:28:57 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( PresidentialPardonForm const &src );
		PresidentialPardonForm( std::string const target );
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=( PresidentialPardonForm const &rhs );

		std::string const	getTarget( void ) const;

		void	execute( Bureaucrat const & executor ) const;
};

#endif
