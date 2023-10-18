/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:59 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/17 17:06:01 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

template< typename T >
class	Array {
	private:
		T *_array;
	public:
		Array( void );
		Array( Array const & src );
		Array( unsigned int n );
		~Array();

		Array operator=( Array const &rhs );

		T operator[]( unsigned int const &index );

		unsigned int size( void ) const;

		T getArray( void ) const;
};

#endif