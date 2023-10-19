/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:41 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/17 17:05:43 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main (void)
{
	Array<char> a(5);
	std::cout << a.size() << std::endl;
	try 
	{
		a[0] = 'a';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << a[0] << std::endl;
	Array<char> b(a);
	std::cout << b.size() << std::endl;
	std::cout << a[0] << std::endl;
	std::cout << b[0] << std::endl;
	try 
	{
		b[0] = 'b';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << a[0] << std::endl;
	std::cout << b[0] << std::endl;
	a = b;
	std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << a[0] << std::endl;
	std::cout << b[0] << std::endl;
	try 
	{
		b[0] = 'c';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << a[0] << std::endl;
	std::cout << b[0] << std::endl;
	
	
	{
		Array<const char> a;
		std::cout << a.size() << std::endl;
	}
	return 0;
}