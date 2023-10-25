/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:40:58 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/20 17:40:59 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
	private:
		std::vector<int> container;
		Span( void );
	public:
		Span( unsigned int N );
		Span( Span const &src );
		~Span();

		Span	&operator=( Span const &rhs );

		void	getContainer( void ) const;
		int		getRemainingCapacity( void ) const;

		void	addNumber( int nb );
		void	addMoreNumbers( int *tab, int tabsize );

		int	shortestSpan( void ) const;
		int	longestSpan( void ) const;

		class	ContainerFullException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Container is full");
				}
		};

		class	NotEnoughValuesException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Span class doesn't contain enough values, need at least 2");
				}
		};
};

#endif