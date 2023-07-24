/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:26:49 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:26:50 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : AAnimal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	return;
}

Dog::Dog( Dog const &src ) : AAnimal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = src.getType();
	this->_brain = new Brain(*src.getBrain());
	return;
}

void	Dog::makeSound() const {
	std::cout << "woof" << std::endl;
	return;
}

Brain	*Dog::getBrain( void ) const {
	return this->_brain;
}

Dog	&Dog::operator=( Dog const &rhs ) {
	if (this != &rhs)
	{
		this->_type = this->getType();
		for (int i = 0; i < 100; i++)
			this->_brain->setIdeas(i, rhs.getBrain()->getIdeas(i));
	}
	return *this;
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
	return;
}
