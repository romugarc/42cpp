/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:24:06 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:24:08 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal( void );
		WrongAnimal( WrongAnimal const &src );
		virtual ~WrongAnimal( void );

		WrongAnimal	&operator=( WrongAnimal const &rhs );

		std::string	getType( void ) const;

		void	makeSound() const;
};

#endif
