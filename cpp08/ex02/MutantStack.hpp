/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:38:46 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/24 17:38:49 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <algorithm>
# include <stack>

template< typename T >
class	MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack( void ) {};
		MutantStack( MutantStack const &src ) { this->c = src.c; };
		~MutantStack() {};

		MutantStack &operator=( MutantStack const &rhs ) {
			this->c = rhs.c;
			return *this;
		};

		typedef typename std::stack<T>::container_type::reverse_iterator iterator;

		iterator begin() { return this->c.rbegin(); };
		iterator end() { return this->c.rend(); };
};

#endif