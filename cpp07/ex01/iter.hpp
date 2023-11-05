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
	int	i = 0;

	while (i < len)
	{
		f(array[i]);
		i++;
	}
}

template < typename T >
void	iter(T const *array, unsigned int len, void (*f)(T const &))
{
	while (i < len)
	{
		f(array[i]);
		i++;
	}
}

#endif