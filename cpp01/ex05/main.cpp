 #include "Harl.hpp"

 int	main( void )
 {
	Harl		client;
	std::string	input;

	while (1)
	{
		input = "Harl";
		std::cout << "Enter a Harl command: ";
		std::getline(std::cin, input);
		if (input != "DEBUG" && input != "INFO" && input != "WARNING" && input != "ERROR")
		{
			std::cout << "Wrong command" << std::endl;
			std::cout << "Valid commands are DEBUG, INFO, WARNING, ERROR" << std::endl;
		}
		else
			client.complain(input);
	}
	return (0);
 }