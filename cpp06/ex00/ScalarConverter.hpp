/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:10:44 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/27 13:10:47 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# define CHAR 1
# define NODISPLAY 2
# define INT 3
# define FLOAT 4
# define DOUBLE 5
# define NAN 6
# define INF 7

class ScalarConverter
{
	public:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const &src );
		~ScalarConverter();

		ScalarConverter &operator=( ScalarConverter const &rhs );

		static void	convert( std::string ch );
};

#endif