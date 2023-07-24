/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:27:06 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:27:09 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

AWrongAnimal::AWrongAnimal( void ) : _type("AWrongAnimal") {
	std::cout << "AWrongAnimal default constructor called" << std::endl;
	return;
}

AWrongAnimal::AWrongAnimal( AWrongAnimal const &src ) : _type(src.getType()) {
	std::cout << "AWrongAnimal copy constructor called" << std::endl;
	return;
}

std::string AWrongAnimal::getType( void ) const {
	return this->_type;
}

void	AWrongAnimal::makeSound() const {
	std::cout << "*lamina sdnuos*" << std::endl;
	return;
}

AWrongAnimal	&AWrongAnimal::operator=( AWrongAnimal const &rhs ) {
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

AWrongAnimal::~AWrongAnimal( void ) {
	std::cout << "AWrongAnimal destructor called" << std::endl;
	return;
}
