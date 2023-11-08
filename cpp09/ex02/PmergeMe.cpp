#include "PmergeMe.hpp"

int error_handler(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "Enter at least 2 positive integers" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (std::isdigit(argv[i][j]) == 0)
			{
				std::cout << "Enter only positive integers without any sign" << std::endl;
				return (1);
			}
		}
		if (argv[i][0] == '\0')
		{
			std::cout << "Enter only positive integers without any sign" << std::endl;
			return (1);
		}
	}
	for (int i = 1; i < argc; i++)
	{
		double	val;

		val = std::atof(argv[i]);
		if (val > 2147483647)
		{
			std::cout << "Positive integers can't be above 2147483647" << std::endl;
			return (1);
		}
	}
	return (0);
}

int	my_pow(int x)
{
	int	result = 1;

	for (int i = 0; i < x; i++)
		result = result * 2;
	return (result);
}

NumbersDeq	*initializeNumbersDeq(int argc, char **argv)
{
	NumbersDeq *nums = new NumbersDeq[argc - 1]; //delete a la fin du programme

	for (int i = 1; i < argc; i++)
    {
		nums[i - 1].nb = std::atoi(argv[i]);
        nums[i - 1].pos.push_back(i - 1);
    }
	for (int i = 0; i < argc - 1; i++)
	{	
		if (i % 2 == 0 && i + 1 < argc - 1)
			nums[i].rf.push_back(&nums[i + 1]);
		else if (i % 2 == 1)
			nums[i].rf.push_back(&nums[i - 1]);
	 	else //nombre impair d'inputs, pas de paire pour le dernier input
		  	nums[i].rf.push_back(NULL);
	}
	return nums;
}

NumbersVec	*initializeNumbersVec(int argc, char **argv)
{
	NumbersVec *nums = new NumbersVec[argc - 1]; //delete a la fin du programme

	for (int i = 1; i < argc; i++)
    {
		nums[i - 1].nb = std::atoi(argv[i]);
        nums[i - 1].pos.push_back(i - 1);
    }
	for (int i = 0; i < argc - 1; i++)
	{	
		if (i % 2 == 0 && i + 1 < argc - 1)
			nums[i].rf.push_back(&nums[i + 1]);
		else if (i % 2 == 1)
			nums[i].rf.push_back(&nums[i - 1]);
	 	else //nombre impair d'inputs, pas de paire pour le dernier input
		  	nums[i].rf.push_back(NULL);
	}
	return nums;
}