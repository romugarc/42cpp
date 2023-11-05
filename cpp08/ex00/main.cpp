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

		try
		{
			it = easyfind(myvector, 20);
			std::cout << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			it = easyfind(myvector, 50);
			std::cout << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		int myints[] = { 10, 20, 30, 40 };
		std::vector<int> myvector (myints, myints+4);
		std::vector<int>::iterator it;

		try
		{
			it = easyfind(myvector, 20);
			std::cout << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			it = easyfind(myvector, 50);
			std::cout << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}