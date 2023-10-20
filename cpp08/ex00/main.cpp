/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:42:17 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/20 16:42:19 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main (void)
{
	{
		int myints[] = { 10, 20, 30, 40 };
		const std::vector<int> myvector (myints, myints+4);
		std::vector<int>::const_iterator it;

		it = easyfind(myvector, 20);
		if (it == myvector.end())
		{
			std::cout << "not found" << std::endl;
		}
		else
			std::cout << *it << std::endl;
	}

	{
		int myints[] = { 10, 20, 30, 40 };
		std::vector<int> myvector (myints, myints+4);
		std::vector<int>::iterator it;

		it = easyfind(myvector, 20);
		if (it == myvector.end())
		{
			std::cout << "not found" << std::endl;
		}
		else
		{
			std::cout << *it << std::endl;
			*it = 10;
			std::cout << *it << std::endl;
		}
	}
}