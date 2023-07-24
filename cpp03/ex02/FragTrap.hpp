/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:06:12 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:06:14 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( FragTrap const &src );
		FragTrap( std::string const name );
		~FragTrap( void );

		FragTrap	&operator=( FragTrap const &rhs );

		void highFivesGuys( void );
};

#endif
