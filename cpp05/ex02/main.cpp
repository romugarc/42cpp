#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main ( void ) {

	std::cout << std::endl << "---------------BUREAUCRAT CREATION TEST : ----------------" << std::endl << std::endl;
	Bureaucrat 				B1;
	
	std::cout << std::endl << "---------------PRESIDENTIAL PARDON CREATION TEST : ----------------" << std::endl << std::endl;
	PresidentialPardonForm	PF1(B1.getName());
	PresidentialPardonForm	PF2("The Evil Chair");
	PresidentialPardonForm	PF3(PF2);
	PresidentialPardonForm	PF4;

	std::cout << std::endl << "---------------ROBOTOMY REQUEST CREATION TEST : ----------------" << std::endl << std::endl;
	RobotomyRequestForm	RF1(B1.getName());
	RobotomyRequestForm	RF2("The Evil Chair");
	RobotomyRequestForm	RF3(RF2);
	RobotomyRequestForm	RF4;

	std::cout << std::endl << "---------------SHRUBBERY CREATION CREATION TEST : ----------------" << std::endl << std::endl;
	ShrubberyCreationForm	SF1(B1.getName());
	ShrubberyCreationForm	SF2("The Evil Chair");
	ShrubberyCreationForm	SF3(SF2);
	ShrubberyCreationForm	SF4;

	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << PF2 << std::endl;
	std::cout << PF3 << std::endl;
	std::cout << PF4 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << RF2 << std::endl;
	std::cout << RF3 << std::endl;
	std::cout << RF4 << std::endl;
	std::cout << SF1 << std::endl;
	std::cout << SF2 << std::endl;
	std::cout << SF3 << std::endl;
	std::cout << SF4 << std::endl;

	std::cout << std::endl << "---------------ASSIGNATION TEST PF4 = PF1 TEST : ----------------" << std::endl << std::endl;
	PF4 = PF1;
	RF4 = RF1;
	SF4 = SF1;

	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << PF4 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << RF4 << std::endl;
	std::cout << SF1 << std::endl;
	std::cout << SF4 << std::endl;

	std::cout << std::endl << "---------------SHRUBBERY CREATION EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------SHRUBBERY CREATION SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << SF1 << std::endl;

	std::cout << std::endl << "---------------PROMOTION TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	try
	{
		B1.incrGrade(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << B1 << std::endl;
	B1.incrGrade(10);
	std::cout << B1 << std::endl;
	
	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << SF1 << std::endl;

	std::cout << std::endl << "---------------SHRUBBERY CREATION EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------SHRUBBERY CREATION SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << SF1 << std::endl;

	std::cout << std::endl << "---------------PROMOTION TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	try
	{
		B1.incrGrade(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << B1 << std::endl;
	B1.incrGrade(7);
	std::cout << B1 << std::endl;
	
	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << SF1 << std::endl;

	std::cout << std::endl << "---------------SHRUBBERY CREATION EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------SHRUBBERY CREATION SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << SF1 << std::endl;

	std::cout << std::endl << "---------------PROMOTION TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	try
	{
		B1.incrGrade(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << B1 << std::endl;
	B1.incrGrade(80);
	std::cout << B1 << std::endl;
	
	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << SF1 << std::endl;

	std::cout << std::endl << "---------------SHRUBBERY CREATION EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------SHRUBBERY CREATION SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << SF1 << std::endl;

	std::cout << std::endl << "---------------PROMOTION TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	B1.incrGrade(32);
	std::cout << B1 << std::endl;
	
	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << SF1 << std::endl;

	std::cout << std::endl << "---------------SHRUBBERY CREATION EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------SHRUBBERY CREATION SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << SF1 << std::endl;

	std::cout << std::endl << "---------------PROMOTION TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	B1.incrGrade(20);
	std::cout << B1 << std::endl;
	
	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << SF1 << std::endl;

	std::cout << std::endl << "---------------SHRUBBERY CREATION EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON EXECUTION TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.executeForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------SHRUBBERY CREATION SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(SF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------ROBOTOMY REQUEST SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(RF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------PRESIDENTIAL PARDON SIGNED TEST : ----------------" << std::endl << std::endl;
	try
	{
		B1.signForm(PF1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---------------FORM DISPLAY TEST : ----------------" << std::endl << std::endl;
	std::cout << B1 << std::endl;
	std::cout << PF1 << std::endl;
	std::cout << RF1 << std::endl;
	std::cout << SF1 << std::endl;

	std::cout << std::endl << "---------------DESTRUCTION CALL : ----------------" << std::endl << std::endl;

	return (0);
}