/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:25:14 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 08:25:15 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int	_nb;
		static int	const	_bits;
	public:
		Fixed( void );
		Fixed( Fixed const &f );
		~Fixed( void );

		Fixed 	&operator=( Fixed const &rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
