#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string commande;
	int	i;
	int	quit;

	quit = 0;
	i = 0;
	while (quit == 0)
	{
		std::getline(std::cin, commande);
		if (commande.compare("EXIT") == 0)
			quit = 1;
		else if (commande.compare("ADD") == 0)
		{
			if (i > 7)
				i = 0;
			phonebook.add_contact(i);
			i++;
		}
		else if (commande.compare("SEARCH") == 0)
		{
			std::string	index;
			bool	done;
			int		n;
			
			n = 0;
			while (n < 8)
			{
				if (phonebook.is_contact(n) == true)
					phonebook.display_existing_contact(n);
				n++;
			}
			done = false;
			while (!done)
			{
				std::cout << "Enter the index of the contact you wish to display" << std::endl;
				std::getline(std::cin, index);
				if (index.empty() == true)
					std::cout << "Index cannot be empty" << std::endl;
				else if (index.length() != 1)
					std::cout << "Index must be one character long" << std::endl;
				else if (!(index[0] >= '0' && index[0] <= '7'))
					std::cout << "Index has to be a number between 0 and 7" << std::endl;
				else
					done = true;
			}
			if (phonebook.is_contact(index[0] - '0') == false)
				std::cout << "Contact does not exist" << std::endl;
			else
				phonebook.display_contact(index[0] - '0');
		}
	}
	return 0;
}