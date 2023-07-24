/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:24:54 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:24:56 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal( void );
		Animal( Animal const &src );
		virtual ~Animal( void );

		Animal	&operator=( Animal const &rhs );

		std::string	getType( void ) const;

		virtual void	makeSound() const;
};

#endif
