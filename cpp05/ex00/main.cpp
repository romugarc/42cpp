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
	try
	{
		Bureaucrat	B2("Jean Patron", 0);
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	B2("Jean Patron", 151);
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat	B2("Jean Patron", 1);
	Bureaucrat	B3(B2);

	std::cout << std::endl << "--Bureaucrats :" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << B2 << std::endl;
	std::cout << B3 << std::endl;

	std::cout << std::endl << "--Grade increase :" << std::endl << std::endl;
	try
	{
		B1.incrGrade(1);
		B2.incrGrade(1);
		B1.incrGrade(1);
		B3.incrGrade(1);
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "--Bureaucrats :" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << B2 << std::endl;
	std::cout << B3 << std::endl;
	std::cout << std::endl << "--Grade decrease :" << std::endl << std::endl;
	try
	{
		B1.decrGrade(1);
		B2.decrGrade(149);
		B3.decrGrade(151);
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
}
