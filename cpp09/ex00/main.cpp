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

int	main (void)
{
	int myints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> deq(myints, myints+10);

  	for (std::vector<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    {
		std::cout << ' ' << &*it;
	}
	std::cout << " " << deq.capacity() << std::endl;
	deq.push_back(10);
	std::cout << deq.capacity() << std::endl;
	for (std::vector<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    {
		std::cout << ' ' << &*it;
	}
	std::cout << std::endl;
	int &b = deq[3];
	std::cout << &deq[3] << "\n" << &b << std::endl;
	//trouver un moyen de check si l'adresse de b correspond toujours au bon element en swapant les elements
	std::cout << &deq[3] << "\n" << &b  << "\n"  << deq[3] << "\n" << deq[4] << "\n" << b << std::endl;
	for (std::vector<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    {
		std::cout << ' ' << *it;
	}
}