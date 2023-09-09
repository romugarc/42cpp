/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:26:44 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/09 10:26:45 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main ( void ) {

	std::cout << std::endl << "--Form Creation :" << std::endl << std::endl;
	PresidentialPardonForm	P1;
	PresidentialPardonForm	P2("Martin Criminel");
	RobotomyRequestForm	R1;
	RobotomyRequestForm	R2("Hugo Patient");
	ShrubberyCreationForm S1;
	ShrubberyCreationForm S2("home");

	std::cout << std::endl << "--Forms :" << std::endl << std::endl;
	std::cout << P1.getTarget() << std::endl;
	std::cout << P1 << std::endl;
	std::cout << P2.getTarget() << std::endl;
	std::cout << P2 << std::endl;
	std::cout << R1.getTarget() << std::endl;
	std::cout << R1 << std::endl;
	std::cout << R2.getTarget() << std::endl;
	std::cout << R2 << std::endl;
	std::cout << S1.getTarget() << std::endl;
	std::cout << S1 << std::endl;
	std::cout << S2.getTarget() << std::endl;
	std::cout << S2 << std::endl;
	P1 = P2;
	R1 = R2;
	S1 = S2;
	std::cout << std::endl << "--F1 = F2 :" << std::endl << std::endl;
	std::cout << P1.getTarget() << std::endl;
	std::cout << P1 << std::endl;
	std::cout << R1.getTarget() << std::endl;
	std::cout << R1 << std::endl;
	std::cout << S1.getTarget() << std::endl;
	std::cout << S1 << std::endl;

	std::cout << std::endl << "--Bureaucrats :" << std::endl << std::endl;
	Bureaucrat	B1("Thomas Nouveau", 150);
	Bureaucrat	B2("Jean Patron", 1);

	std::cout << B1 << std::endl;
	std::cout << B2 << std::endl;

	std::cout << std::endl << "--Thomas Nouveau tries signing and executing forms :" << std::endl << std::endl;
	std::cout << std::endl << "--Shrubbery :" << std::endl << std::endl;
	try
	{
		B1.signForm(S1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		B1.executeForm(S1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	B1.incrGrade(5);
	try
	{
		B1.signForm(S1);
		B1.executeForm(S1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "--Jean Patron tries to execute the form instead :" << std::endl << std::endl;
	try
	{
		B2.executeForm(S1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--Robotomy :" << std::endl << std::endl;
	try
	{
		B1.signForm(R1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		B1.executeForm(R1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	B1.incrGrade(73);
	try
	{
		B1.signForm(R1);
		B1.executeForm(R1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "--Jean Patron tries to execute the form instead :" << std::endl << std::endl;
	try
	{
		B2.executeForm(R1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--Presidential :" << std::endl << std::endl;
	try
	{
		B1.signForm(P1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		B1.executeForm(P1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	B1.incrGrade(47);
	try
	{
		B1.signForm(P1);
		B1.executeForm(P1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "--Jean Patron tries to execute the form instead :" << std::endl << std::endl;
	try
	{
		B2.executeForm(P1);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::UnsignedFormException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--Forms :" << std::endl << std::endl;
	std::cout << P1.getTarget() << std::endl;
	std::cout << P1 << std::endl;
	std::cout << P2.getTarget() << std::endl;
	std::cout << P2 << std::endl;
	std::cout << R1.getTarget() << std::endl;
	std::cout << R1 << std::endl;
	std::cout << R2.getTarget() << std::endl;
	std::cout << R2 << std::endl;
	std::cout << S1.getTarget() << std::endl;
	std::cout << S1 << std::endl;
	std::cout << S2.getTarget() << std::endl;
	std::cout << S2 << std::endl;
	std::cout << std::endl << "--Destruction :" << std::endl << std::endl;
	return (0);
}
