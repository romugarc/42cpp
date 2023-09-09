/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:28:38 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:28:39 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main ( void ) {

	std::cout << std::endl << "--Intern :" << std::endl << std::endl;
	Intern someRandomIntern;
	AForm* rrf;
	
	std::cout << std::endl << "--Bureaucrat :" << std::endl << std::endl;
	Bureaucrat	B2("Jean Patron", 1);

	std::cout << B2 << std::endl;
	
	rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");
	std::cout << *rrf << std::endl;
	try
	{
		B2.signForm(*rrf);
		B2.executeForm(*rrf);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete rrf;
	std::cout << std::endl;
	rrf = someRandomIntern.makeForm("ShrubberyCreation", "Jardin");
	std::cout << *rrf << std::endl;
	try
	{
		B2.signForm(*rrf);
		B2.executeForm(*rrf);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete rrf;
	std::cout << std::endl;
	rrf = someRandomIntern.makeForm("PresidentialPardon", "Obama");
	std::cout << *rrf << std::endl;
	try
	{
		B2.signForm(*rrf);
		B2.executeForm(*rrf);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete rrf;
	std::cout << std::endl;
	rrf = someRandomIntern.makeForm("SomeForm", "Bender");
	delete rrf;

	std::cout << std::endl << "--Destruction :" << std::endl << std::endl;
}
