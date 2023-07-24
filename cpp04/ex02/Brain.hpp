/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:26:41 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:26:42 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"
# include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain( void );
		Brain( Brain const &src );
		~Brain( void );

		Brain	&operator=( Brain const &rhs );

		std::string	getIdeas( unsigned int n ) const;

		void	setIdeas( unsigned int n, std::string idea );
};

#endif
