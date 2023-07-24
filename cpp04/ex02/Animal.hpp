/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:26:32 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:26:33 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal( void );
		AAnimal( AAnimal const &src );
		virtual ~AAnimal( void );

		AAnimal	&operator=( AAnimal const &rhs );

		std::string	getType( void ) const;

		virtual void	makeSound() const = 0;
};

#endif
