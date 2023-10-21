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

	//ajouter test addnumber tout seul + formater pour que tout soit clair + ajouter tests du sujet
	try
	{
		span.addMoreNumbers(myints, 8);
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	
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
	return 0;
}