/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:40:44 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/20 17:40:47 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main(void)
{
	Span span(8);
	int myints[] = {11, 2, 13, 4, 15, 6, 7, 8, 9};
	int	toadd = 8;

	try
	{
		span.addNumber(12);
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	span.getContainer();
	
	std::cout << "try adding: " << toadd << " numbers to container of remaining capacity: " << span.getRemainingCapacity() << std::endl;
	try
	{
		span.addMoreNumbers(myints, toadd);
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	span.getContainer();
	
	try
	{
		std::cout << span.longestSpan() << std::endl;
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	try
	{
		std::cout << span.shortestSpan() << std::endl;
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	std::cout << "-------Tests sujet------" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		sp.getContainer();

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}