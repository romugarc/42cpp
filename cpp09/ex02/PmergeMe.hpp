/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 06:54:11 by rgarcia           #+#    #+#             */
/*   Updated: 2023/11/09 06:54:13 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <stdlib.h>
# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <time.h>

struct NumbersDeq {
	int	nb;
	std::deque<int>	pos;
	std::deque<NumbersDeq*> rf;
};

struct NumbersVec {
	int	nb;
	std::vector<int> pos;
	std::vector<NumbersVec*> rf;
};

int error_handler(int argc, char **argv);
int	my_pow(int x);
NumbersDeq	*initializeNumbersDeq(int argc, char **argv);
NumbersVec	*initializeNumbersVec(int argc, char **argv);

template < typename T >
int	my_is_sorted(T deq, int size)
{
	int	prev = deq[0]->nb;
	for (int i = 0; i < size; i++)
	{
		if (prev > deq[i]->nb)
			return 0;
		prev = deq[i]->nb;
	}
	return 1;
}

template < typename T >
T	adjustPos(T nums, size_t start)
{
	for (size_t i = start; i < nums.size(); i++)
	{
		nums[i]->pos.pop_back();
		nums[i]->pos.push_back(i);
	}
	return (nums);
}

template < typename T >
void	formPairs(T nums, int size)
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

template < typename T >
T	reorderInGroups(T Tiny)
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

template < typename T >
int	binarySearch(T bigS, T Tiny, size_t index)
{
	size_t	xmin = 0;
	size_t	xmax;
	size_t	x;

	if (Tiny[index]->rf.back() == NULL)
		xmax = bigS.size() - 1;
	else
		xmax = Tiny[index]->rf.back()->pos.back();
	x = (xmax - xmin) / 2;
	while ((xmax - xmin) > 1)
	{
		if (Tiny[index]->nb <= bigS[x]->nb)
		{
			xmax = x - 1;
			x = (xmax - xmin) / 2;
		}
		else
		{
			xmin = x + 1;
			x = xmin + ((xmax - xmin) / 2);
		}
	}
	if (Tiny[index]->nb <= bigS[xmax]->nb) //on va toujours comparer avec le nb de droite
	{
		if (Tiny[index]->nb <= bigS[xmin]->nb)
			return (xmin); //insertion avant le plus petit des 2 nb
		else
			return (xmax); //insertion entre les 2 nb restants
	}
	else
		return (xmax + 1); //insertion apres le plus grand des 2 nb
}

template < typename T >
T mergeSort(T nums, int size)
{
	if (size == 2)
	{
		if (nums[0]->nb > nums[1]->nb)
			std::swap(nums[0], nums[1]);
	}
	if (my_is_sorted(nums, size) == 1)
	{
		return nums;
	}
	T bigS;
	T Tiny;
	for (int i = 0; i < size; i = i + 2)
	{
		if (size % 2 == 1 && i == size - 1) //nombre impair seul
		{
			Tiny.push_back(nums[i]);
			break;
		}
		if (nums[i]->nb > nums[i]->rf.back()->nb)
		{
			bigS.push_back(nums[i]);
			Tiny.push_back(nums[i + 1]);
		}
		else
		{
			bigS.push_back(nums[i + 1]);
			Tiny.push_back(nums[i]);
		}
	}
	formPairs(bigS, bigS.size());
	bigS = mergeSort(bigS, bigS.size());
	//insertion
	for (size_t i = 0; i < Tiny.size(); i++)
		Tiny[i]->pos.push_back(i);
	for (size_t i = 0; i < bigS.size(); i++)
	{
		bigS[i]->rf.pop_back();
		bigS[i]->pos.push_back(i);
	}
	bigS.insert(bigS.begin(), bigS[0]->rf.back());
	Tiny.erase(Tiny.begin()+bigS[0]->pos.back());
	bigS[0]->pos.pop_back();
	adjustPos(bigS, 0);
	//swap Tiny
	Tiny = reorderInGroups(Tiny);
	adjustPos(Tiny, 0);
	//binary search
	int	x;
	while(Tiny.size() > 0)
	{
		x = binarySearch(bigS, Tiny, 0);
		bigS.insert(bigS.begin()+x, Tiny[0]);
		Tiny.erase(Tiny.begin());
		bigS[x]->pos.pop_back();
		adjustPos(Tiny, 0);
		adjustPos(bigS, 0);
	}
	return bigS;
}

#endif
