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

class Span
{
	private:
		std::vector<int> container;
	public:
		Span( void );
		Span( unsigned int N );
		Span( Span const &src );
		~Span();

		Span	&operator=( Span const &rhs );

		void	addNumber( int nb );
		void	addMoreNumbers( int nb ); //parametres incomplets

		int	shortestSpan( void ) const;
		int	longestSpan( void ) const;
};

#endif