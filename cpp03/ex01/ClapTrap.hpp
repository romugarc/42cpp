/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:03:37 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:03:38 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap 
{
	protected:
		std::string		_Name;
		unsigned int	_Hit_Points;
		unsigned int	_Energy_Points;
		unsigned int	_Attack_Damage;
	public:
		ClapTrap( void );
		ClapTrap( std::string const name );
		ClapTrap( ClapTrap const &src );
		~ClapTrap( void );

		ClapTrap	&operator=( ClapTrap const &rhs );

		void		attack( const std::string &target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );

		std::string 	getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;

		void	setName(std::string name);
		void	setHitPoints(unsigned int hp);
		void	setEnergyPoints(unsigned int ep);
		void	setAttackDamage(unsigned int ad);
};

#endif
