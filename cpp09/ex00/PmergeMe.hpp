#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <stdlib.h>
# include <limits>
# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>

struct Numbers {
	int	nb;
	std::deque<int>	pos;
	std::deque<Numbers*> rf;
};

int error_handler(int argc, char **argv);
int	my_is_sorted_deque(std::deque<Numbers*> deq, int size);
Numbers	*initializeNumbers(int argc, char **argv);
void	dequeFormPairs(std::deque<Numbers*> nums, int size);

#endif