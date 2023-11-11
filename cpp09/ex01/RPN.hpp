/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 06:56:27 by rgarcia           #+#    #+#             */
/*   Updated: 2023/11/09 06:57:06 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <list>

class RPN
{
	private:
		std::list<double> _list;
	public:
		RPN( void );
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );

		void	calculate(char operand);

		void	pushToList(char c);
		
		double	getResult();
		double	getSize();

		class	DivisionByZeroException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
