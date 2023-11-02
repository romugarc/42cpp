/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:31:02 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/17 11:31:04 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {
}

Serializer::Serializer( Serializer const &src ) {
	*this = src;
}

Serializer	&Serializer::operator=( Serializer const &rhs ) {
	(void)rhs;
	return *this;
}

Serializer::~Serializer() {
}

uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t result = reinterpret_cast<uintptr_t>(ptr);

    return ( result );
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data *data = reinterpret_cast<Data *>(raw);
    
    return ( data );
}