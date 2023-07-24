/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:27:42 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 08:30:15 by rgarcia          ###   ########.fr       */
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

		bool	operator==( Fixed const &rhs ) const;
		bool	operator!=( Fixed const &rhs ) const;
		bool	operator< ( Fixed const &rhs ) const;
		bool	operator> ( Fixed const &rhs ) const;
		bool	operator<=( Fixed const &rhs ) const;
		bool	operator>=( Fixed const &rhs ) const;

		Fixed	operator+( Fixed const &rhs );
		Fixed	operator-( Fixed const &rhs );
		Fixed	operator*( Fixed const &rhs );
		Fixed	operator/( Fixed const &rhs );

		Fixed	&operator++( void );
		Fixed	operator++( int );
		Fixed	&operator--( void );
		Fixed	operator--( int );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt ( void ) const;

		static Fixed		&min( Fixed &nb_1, Fixed &nb_2 );
		static Fixed const	&min( Fixed const &nb_1, Fixed const &nb_2 );
		static Fixed		&max( Fixed &nb_1, Fixed &nb_2 );
		static Fixed const	&max( Fixed const &nb_1, Fixed const &nb_2 );
};

std::ostream	&operator<<( std::ostream &o, Fixed const &src );

#endif
