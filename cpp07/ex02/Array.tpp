# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Array.tpp                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:06:51 by rgarcia           #+#    #+#              #
#    Updated: 2023/10/17 17:06:59 by rgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "Array.tpp"

Array::Array( void ) : _array(NULL) {
}

Array::Array( unsigned int n ) : _array(new T[n]) {
}

Array::Array( Array const &src ) : _array(new T[src.size()]) {
	this->_array = src->_array;
}

Array::~Array() {
	delete [] _array;
}

Array Array::operator=(Array const &rhs) {
	for (int i = 0; i < rhs.size(); i++)
		this->_array[i] = rhs._array[i];
}