/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:25:07 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:25:08 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat( void );
		Cat( Cat const &src );
		~Cat( void );

		Cat	&operator=( Cat const &rhs );

		virtual void	makeSound() const;
		Brain	*getBrain( void ) const;
};

#endif
