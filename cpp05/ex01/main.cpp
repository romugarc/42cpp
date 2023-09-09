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

	std::cout << std::endl << "---------------FORM WRONG CREATION TEST : ----------------" << std::endl << std::endl;
	try
	{
		Form F1 = Form("salut", -3, 2);
	}
	catch(const std::exception &e)
	{
		std::cout << "couldn't create Form because : ";
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "---------------BUREAUCRAT CREATION : ----------------" << std::endl << std::endl;
	Bureaucrat	B1;
	Bureaucrat	B2("Bureau Crate", 1);
	Bureaucrat	B3(B2);
	Bureaucrat	B4("Speedy Gonzales", 56);

	std::cout << std::endl << "---------------DISPLAY BUREAUCRAT : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << B2 << std::endl;
	std::cout << B3 << std::endl;
	std::cout << B4 << std::endl;

	std::cout << std::endl << "---------------CORRECT FORMULAR CREATION : ----------------" << std::endl << std::endl;
	Form F1;
	Form F2("low level", 150, 150);
	Form F3("mid level", 56, 56);

	std::cout << std::endl << "---------------DISPLAY FORM : ----------------" << std::endl << std::endl;
	std::cout << F1 << std::endl;
	std::cout << F2 << std::endl;
	std::cout << F3 << std::endl;

	std::cout << std::endl << "---------------SIGNING FORM1 : ----------------" << std::endl << std::endl;
	try
	{
		F1.beSigned(B1);
	}
	catch(const Form::GradeTooLowException & e)
	{
		std::cerr << e.what() << '\n';
	}
	F1.beSigned(B2);
	F1.beSigned(B3);
	try
	{
		F1.beSigned(B4);
	}
	catch(const Form::GradeTooLowException & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------SIGNING FORM2 : ----------------" << std::endl << std::endl;
	F2.beSigned(B1);
	F2.beSigned(B2);
	F2.beSigned(B3);
	F2.beSigned(B4);

	std::cout << std::endl << "---------------SIGNING FORM3 : ----------------" << std::endl << std::endl;
	try
	{
		F3.beSigned(B1);
	}
	catch(const Form::GradeTooLowException & e)
	{
		std::cerr << e.what() << '\n';
	}
	F3.beSigned(B2);
	F3.beSigned(B3);
	F3.beSigned(B4);

	std::cout << std::endl << "---------------DISPLAY FORM : ----------------" << std::endl << std::endl;
	std::cout << F1 << std::endl;
	std::cout << F2 << std::endl;
	std::cout << F3 << std::endl;

	std::cout << std::endl << "---------------DESTRUCTION CALL : ----------------" << std::endl << std::endl;

	return (0);
}
