/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:25:14 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:25:16 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog( void );
		Dog( Dog const &src );
		~Dog( void );

		Dog	&operator=( Dog const &rhs );

		virtual void	makeSound() const;
		Brain	*getBrain( void ) const;
};

#endif
