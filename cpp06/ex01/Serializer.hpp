/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:31:09 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/17 11:31:10 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	public:
		Serializer( void );
		Serializer( Serializer const &src );
		~Serializer();

		Serializer &operator=( Serializer const &rhs );

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif
