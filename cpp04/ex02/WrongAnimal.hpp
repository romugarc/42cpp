/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:27:04 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:27:05 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class AWrongAnimal
{
	protected:
		std::string	_type;
	public:
		AWrongAnimal( void );
		AWrongAnimal( AWrongAnimal const &src );
		virtual ~AWrongAnimal( void );

		AWrongAnimal	&operator=( AWrongAnimal const &rhs );

		std::string	getType( void ) const;

		void	makeSound() const = 0;
};

#endif
