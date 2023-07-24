/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:26:57 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:26:59 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class WrongCat : public AWrongAnimal
{
	private:
		Brain	*_brain;
	public:
		WrongCat( void );
		WrongCat( WrongCat const &src );
		~WrongCat( void );

		WrongCat	&operator=( WrongCat const &rhs );

		virtual void	makeSound() const;
		Brain	*getBrain( void ) const;
};

#endif
