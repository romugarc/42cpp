/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warnora <warnora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:24:06 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/04 05:51:58 by warnora          ###   ########.fr       */
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
