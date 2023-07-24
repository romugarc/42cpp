/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:26:30 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 08:26:32 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int	_nb;
		static int	const	_bits;
	public:
		Fixed( void );
		Fixed( Fixed const &f );
		Fixed( int const toconvert );
		Fixed( float const toconvertf );
		~Fixed( void );

		Fixed 	&operator=( Fixed const &rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt ( void ) const;
};

std::ostream	&operator<<( std::ostream &o, Fixed const &src );

#endif
