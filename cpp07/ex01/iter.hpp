/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:08:19 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/17 12:08:21 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template < typename T >
void	iter(T *array, unsigned int len, void (*f)(T &))
{
	while (len > 0)
	{
		f(array[len - 1]);
		len--;
	}
}

template < typename T >
void	iter(T const *array, unsigned int len, void (*f)(T const &))
{
	while (len > 0)
	{
		f(array[len - 1]);
		len--;
	}
}

#endif