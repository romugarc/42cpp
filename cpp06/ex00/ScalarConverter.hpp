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

template< typename T >
int	isInsideLimits(char const *ch)
{
	double val = std::atof(ch);

	if (val > 0)
	{
		if (val < std::numeric_limits<T>::min() || val > std::numeric_limits<T>::max())
			return (0);
	}
	else
	{
		if (val < -std::numeric_limits<T>::max())
			return (0);
	}
	return (1);
}

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