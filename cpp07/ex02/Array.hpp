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

class	Array {
	public:
		Array( void );
		Array( Array const & src );
		Array( unsigned int n );
		~Array();

		Array operator=( Array const &rhs );
};

#endif