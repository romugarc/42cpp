/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:25:28 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:25:30 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main ( void ) {

	std::cout << std::endl << "--Form Creation :" << std::endl << std::endl;
	Form	F1;
	try
	{
		Form	F2("Special Form", 0, 1);
	}
	catch(const Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	F2("Special Form", 1, 0);
	}
	catch(const Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	F2("Special Form", 151, 1);
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	F2("Special Form", 1, 151);
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	Form	F2("Special Form", 1, 150);
	Form	F3("Boring Form", 150, 1);

	std::cout << std::endl << "--Forms :" << std::endl << std::endl;
	std::cout << F1 << std::endl;
	std::cout << F2 << std::endl;
	std::cout << F3 << std::endl;
	F1 = F2;
	std::cout << std::endl << "--F1 = F2 :" << std::endl << std::endl;
	std::cout << F1 << std::endl;

	std::cout << std::endl << "--Bureaucrats :" << std::endl << std::endl;
	Bureaucrat	B1("Thomas Nouveau", 150);
	Bureaucrat	B2("Jean Patron", 1);

	std::cout << B1 << std::endl;
	std::cout << B2 << std::endl;

	std::cout << std::endl << "--Thomas Nouveau tries signing forms :" << std::endl << std::endl;
	try
	{
		B1.signForm(F3);
		B1.signForm(F2);
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "--New Boring Form :" << std::endl << std::endl;
	Form	F4(F3);
	std::cout << F4 << std::endl;
	std::cout << std::endl << "--Jean Patron tries signing forms :" << std::endl << std::endl;
	try
	{
		B2.signForm(F4);
		B2.signForm(F2);
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "--Destruction :" << std::endl << std::endl;
}
