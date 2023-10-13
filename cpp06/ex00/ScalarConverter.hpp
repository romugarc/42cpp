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
# include <stdlib.h>
# include <limits>
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define NAN 5
# define INF 6

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