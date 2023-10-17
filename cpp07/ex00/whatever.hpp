/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:33:49 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/17 11:33:51 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template< typename T >
void	swap( T &a, T &b ) {
	T c = a;

	a = b;
	b = c;
}

template< typename T >
T	&min( T &a, T &b ) {
	if (a < b)
		return a;
	else
		return b;
}

template< typename T >
T	const &min( T const &a, T const &b ) {
	if (a < b)
		return a;
	else
		return b;
}

template< typename T >
T	&max( T &a, T &b ) {
	if (a > b)
		return a;
	else
		return b;
}

template< typename T >
T	const &max( T const &a, T const &b ) {
	if (a > b)
		return a;
	else
		return b;
}

#endif