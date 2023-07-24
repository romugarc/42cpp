/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:26:53 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:26:55 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "------------test ex00------------" << std::endl;
	//const AAnimal* meta = new AAnimal(); //decommenter
	const AAnimal* ju = new Dog();
	const AAnimal* io = new Cat();

	std::cout << ju->getType() << " " << std::endl;
	std::cout << io->getType() << " " << std::endl;
	io->makeSound(); //will output the cat sound!
	ju->makeSound();
	//meta->makeSound();

	delete io;
	delete ju;
	//delete meta;

	//const AWrongAnimal* wrong = new AWrongAnimal(); //decommenter
	const AWrongAnimal* k = new WrongCat();

	std::cout << k->getType() << " " << std::endl;
	k->makeSound(); //will output the wrongcat sound!
	//wrong->makeSound();

	delete k;
	//delete wrong;

	std::cout << "------------tests ex01------------" << std::endl;

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "------------AAnimal tab------------" << std::endl;
	std::cout << "--------------Dogs----------" << std::endl;
	AAnimal	*animal[100];
	int n;

	n = 0;
	while (n < 50)
	{
		animal[n] = new Dog;
		std::cout << animal[n]->getType() << std::endl;
		n++;
	}
	std::cout << "-------------Cats-----------" << std::endl;
	while (n < 100)
	{
		animal[n] = new Cat;
		std::cout << animal[n]->getType() << std::endl;
		n++;
	}
	std::cout << "-----------Delete tab-------------" << std::endl;
	n = 0;
	while (n < 100)
	{
		delete animal[n];
		n++;
	}
	std::cout << "------------------------" << std::endl;
	Cat* catA = new Cat();
	const Cat* catB = new Cat(*catA);
	const Brain	*brainA;
	const Brain	*brainB;

	*catA = *catB;

	std::cout << "------------catA sniff------------" << std::endl;
	for (int k = 0; k < 100; k++)
		catA->getBrain()->setIdeas(k, "sniff");
	for (int k = 0; k < 100; k++)
		std::cout << catA->getBrain()->getIdeas(k) << std::endl;
	std::cout << "------------catB------------" << std::endl;
	for (int k = 0; k < 100; k++)
		std::cout << catB->getBrain()->getIdeas(k) << std::endl;
	std::cout << "------------catA snuff------------" << std::endl;
	for (int k = 0; k < 100; k++)
		catA->getBrain()->setIdeas(k, "snuff");
	for (int k = 0; k < 100; k++)
		std::cout << catA->getBrain()->getIdeas(k) << std::endl;
	std::cout << "------------catB------------" << std::endl;
	for (int k = 0; k < 100; k++)
		std::cout << catB->getBrain()->getIdeas(k) << std::endl;
	std::cout << "------------brain tests------------" << std::endl;
	brainA = catA->getBrain();
	brainB = catB->getBrain();
	std::cout << brainA << std::endl << brainB << std::endl;
	std::cout << catA->getBrain()->getIdeas(42) << std::endl;
	std::cout << catB->getBrain()->getIdeas(42) << std::endl;
	std::cout << brainB->getIdeas(42) << std::endl;
	std::cout << brainA->getIdeas(42) << std::endl;

	std::cout << "------------------------" << std::endl;
	delete catA;
	delete catB;

	return 0;
}
