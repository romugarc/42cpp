/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:25:04 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:25:05 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	return;
}

Cat::Cat( Cat const &src ) : Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = src.getType();
	this->_brain = new Brain(*src.getBrain());
	return;
}

void	Cat::makeSound() const {
	std::cout << "meow" << std::endl;
	return;
}

Brain	*Cat::getBrain( void ) const {
	return this->_brain;
}

Cat	&Cat::operator=( Cat const &rhs ) {
	if (this != &rhs)
	{
		this->_type = this->getType();
		for (int i = 0; i < 100; i++)
			this->_brain->setIdeas(i, rhs.getBrain()->getIdeas(i));
	}
	return *this;
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
	return;
}
