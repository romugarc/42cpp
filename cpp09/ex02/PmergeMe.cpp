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
		if (std::isdigit(argv[i][0]) == 0)
		{
			std::cout << "Enter only positive integers (+ doesn't count because I said so)" << std::endl;
			return (1);
		}
	}
	return (0);
}

int	my_is_sorted_deque(std::deque<Numbers*> deq, int size)
{
	int	prev = deq[0]->nb;
	for (int i = 0; i < size; i++)
	{
		if (prev > deq[i]->nb)
			return 0;
		prev = deq[i]->nb;
	}
    std::cout << "yay" << std::endl;
	return 1;
}

Numbers	*initializeNumbers(int argc, char **argv)
{
	Numbers *nums = new Numbers[argc - 1]; //delete a la fin du programme

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

void	dequeFormPairs(std::deque<Numbers*> nums, int size)
{
	for (int i = 0; i < size; i++)
	{	
		if (i % 2 == 0 && i + 1 < size)
			nums[i]->rf.push_back(nums[i + 1]);
		else if (i % 2 == 1)
			nums[i]->rf.push_back(nums[i - 1]);
	 	else //nombre impair d'inputs, pas de paire pour le dernier input
		  	nums[i]->rf.push_back(NULL);
	}
}

std::deque<Numbers*>	dequeAdjustPos(std::deque<Numbers*> nums, size_t start)
{
	for (size_t i = start; i < nums.size(); i++)
	{
		nums[i]->pos.pop_back();
		nums[i]->pos.push_back(i);
	}
	return (nums);
}

int	my_pow(int x)
{
	int	result = 1;

	for (int i = 0; i < x; i++)
		result = result * 2;
	return (result);
}

std::deque<Numbers*>	dequeReorderInGroups(std::deque<Numbers*> Tiny)
{
	size_t	rangemin = 0;
	size_t	rangemax = 2;
	int	x = 2;
	int	currgrp;
	int	futuregrp;

	while (rangemax <= Tiny.size())
	{
		currgrp = rangemax - rangemin;
		futuregrp = my_pow(x) - currgrp;
		std::reverse(Tiny.begin()+rangemin, Tiny.begin()+rangemax);
		rangemin = rangemax;
		rangemax = rangemax + futuregrp;
		if (rangemax > Tiny.size() && rangemin < Tiny.size())
			rangemax = Tiny.size();
		x++;
	}
	return (Tiny);
}