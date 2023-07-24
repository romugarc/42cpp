/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:22:30 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:22:31 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	return;
}

Cat::Cat( Cat const &src ) : Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = src.getType();
	return;
}

void	Cat::makeSound() const {
	std::cout << "meow" << std::endl;
	return;
}

Cat	&Cat::operator=( Cat const &rhs ) {
	if (this != &rhs)
		this->_type = this->getType();
	return *this;
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
	return;
}
