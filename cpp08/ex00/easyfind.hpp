/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:42:23 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/20 16:42:24 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

class	NotFoundException : public std::exception {
	public:
		virtual const char *what() const throw();
};

template < typename T >
typename T::iterator	easyfind(T &container, int nb)
{
	typename T::iterator it = std::find(container.begin(), container.end(), nb);

	if (it == container.end())
		throw NotFoundException();
	return (it);
}

template < typename T >
typename T::const_iterator	easyfind(T const &container, int nb)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), nb);
	
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

#endif