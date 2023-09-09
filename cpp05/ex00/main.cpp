/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:12:35 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:12:45 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main ( void ) {

	std::cout << std::endl << "--Bureaucrat Creation :" << std::endl << std::endl;
	Bureaucrat	B1;
	Bureaucrat	B2("Bureau Crate", 1);
	Bureaucrat	B3(B2);

	std::cout << std::endl << "--Bureaucrats :" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << B2 << std::endl;
	std::cout << B3 << std::endl;

	std::cout << std::endl << "--Grade increase :" << std::endl << std::endl;
	B1.incrGrade(42);
	try
	{
		B2.incrGrade(42);
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--B1 = B2 :" << std::endl << std::endl;
	B1 = B2;

	std::cout << std::endl << "--Bureaucrats :" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << B2 << std::endl;
	std::cout << B3 << std::endl;

	std::cout << std::endl << "--Grade decrease :" << std::endl << std::endl;
	B2.decrGrade(130);
	try
	{
		B3.decrGrade(150);
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--Bureaucrats :" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << B2 << std::endl;
	std::cout << B3 << std::endl;

	std::cout << std::endl << "--Bureaucrat Destruction :" << std::endl << std::endl;
	return (0);
}
