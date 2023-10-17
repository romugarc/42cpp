/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:30:36 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/17 11:30:39 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data( void ) : _realdata("realdata"), _numdata(42.42) {
}

Data::Data( Data const &src ) : _realdata(src.getReal()), _numdata(src.getNum()) {
	*this = src;
}

Data	&Data::operator=( Data const &rhs ) {
	(void)rhs;
	return *this;
}

Data::~Data() {
}

std::string Data::getReal( void ) const {
    return( _realdata );
}

double  Data::getNum( void ) const {
    return ( _numdata );
}
