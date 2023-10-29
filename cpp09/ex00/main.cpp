/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:48:52 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/27 16:48:54 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

struct numbers {
	int	nb;
	std::deque<numbers*> rf;
};

int	main (void)
{
	{
		int max = 10;
		int myints[max] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		numbers nums[max];
		for (int i = 0; i < 10; i++)
			nums[i].nb = myints[i];
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0 && i + 1 < max)
				nums[i].rf.push_back(&nums[i + 1]);
			else if (i % 2 == 1)
				nums[i].rf.push_back(&nums[i - 1]);
			// else //nombre impair d'inputs, pas de paire pour le dernier input
			// 	nums[i].rf = NULL;
		}

		for (int i = 0; i < 10; i++)
			std::cout << ' ' << &nums[i];
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << nums[i].nb << "               " ;
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << ' ' << nums[i].rf.back();
		std::cout << std::endl;

		std::deque<numbers*> deq;
		for (int i = 0; i < 10; i++)
			deq.push_back(&nums[i]);
		for (int i = 0; i < 10; i++)
			//std::cout << ' ' << deq[i].nb << deq[i].rf->nb;
			std::cout << ' ' << deq[i]->nb << deq[i]->rf.back();
		std::cout << std::endl;
		std::iter_swap(deq.begin(), deq.begin()+3);
		for (int i = 0; i < 10; i++)
			//std::cout << ' ' << deq[i].nb << deq[i].rf->nb;
			std::cout << ' ' << deq[i]->nb << deq[i]->rf.back();
		std::cout << std::endl;
		// for (int i = 0; i < 10; i++)
		// {
		// 	std::cout << &deq[i]->rf.back() << std::endl;
		// 	std::cout << &nums[i].rf.back() << std::endl;
		// }
		for (std::deque<numbers*>::iterator it = deq.begin(); it != deq.end(); ++it)
     	{
	 		std::cout << ' ' << *it;
	 	}
		std::cout << std::endl;
		for (std::deque<numbers*>::iterator it = deq.begin(); *it != nums[0].rf.back(); ++it)
     	{
	 		std::cout << ' ' << *it;
	 	}
		std::cout << std::endl;
		////Tout ceci prouve que on peut stocker des références à nos nombres et les utiliser mais dans la recherche de l'iterator, on fait des comparaisons.... donc valide ou pas?
		//Faire un while (it = deq.begin() != nums[0].rf.back()) { it++ et substring_size++ } comme ca on a la taille de la substring et on peut faire nos divs
	}
	// {
	// 	int myints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// 	std::deque<int> deq(myints, myints+10);

  	// 	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    // 	{
	// 		std::cout << ' ' << &*it;
	// 	}
	// 	//std::cout << " " << deq.capacity() << std::endl;
	// 	//deq.push_back(10);
	// 	//std::cout << deq.capacity() << std::endl;
	// 	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    // 	{
	// 		std::cout << ' ' << &*it;
	// 	}
	// 	std::cout << std::endl;
	// 	int &b = deq[3];
	// 	std::cout << &deq[3] << "\n" << &b  << "\n"  << deq[3] << "\n" << b << std::endl;
	// 	//trouver un moyen de check si l'adresse de b correspond toujours au bon element en swapant les elements
	// 	std::iter_swap(deq.begin(), deq.begin()+3);
	// 	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    // 	{
	// 		std::cout << ' ' << &*it;
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << &deq[3] << "\n" << &b  << "\n"  << deq[3] << "\n" << b << std::endl;
	// 	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    // 	{
	// 		std::cout << ' ' << *it;
	// 	}
	// 	std::cout << std::endl;
	// }
}