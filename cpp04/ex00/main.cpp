/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warnora <warnora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:22:42 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/04 06:06:43 by warnora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	const WrongCat* c = new WrongCat();

	std::cout << wrong->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	k->makeSound(); //will output the wronganimal sound!
	c->makeSound(); //will output the wrongcat sound!
	wrong->makeSound();

	delete k;
	delete wrong;
	delete c;
	return 0;
}
