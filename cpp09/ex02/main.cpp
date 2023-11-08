/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:48:52 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/27 16:48:54 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	my_is_sorted_vector(std::vector<Numbers*> vec, int size)
{
	int	prev = vec[0]->nb;
	for (int i = 0; i < size; i++)
	{
		if (prev > vec[i]->nb)
			return 0;
		prev = vec[i]->nb;
	}
	return 1;
}

std::vector<Numbers*>	vectorAdjustPos(std::vector<Numbers*> nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		nums[i]->pos.pop_back();
		nums[i]->pos.push_back(i);
		std::cout << nums[i]->pos.back() << nums.size() << std::endl;
	}
	return (nums);
}

int	dequeBinarySearch(std::deque<Numbers*> bigS, std::deque<Numbers*> Tiny, size_t index)
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

std::deque<Numbers*> dequeMergeSort(std::deque<Numbers*> nums, int size)
{
	if (size == 2)
	{
		if (nums[0]->nb > nums[1]->nb)
			std::iter_swap(nums[0], nums[1]);
	}
	if (my_is_sorted_deque(nums, size) == 1)
		return nums;
	std::deque<Numbers*> bigS;
	std::deque<Numbers*> Tiny;
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
	dequeFormPairs(bigS, bigS.size());
	bigS = dequeMergeSort(bigS, bigS.size());
	//insertion
	for (size_t i = 0; i < Tiny.size(); i++)
		Tiny[i]->pos.push_back(i);
	for (size_t i = 0; i < bigS.size(); i++)
	{
		bigS[i]->rf.pop_back();
		bigS[i]->pos.push_back(i);
	}
	bigS.insert(bigS.begin(), bigS[0]->rf.back());
	Tiny.erase(Tiny.begin()+bigS[0]->pos.back()); //le premier element de bigS appartenait a Tiny donc pas besoin de rf
	bigS[0]->pos.pop_back();
	dequeAdjustPos(bigS, 0);
	// for (size_t i = 0; i < bigS.size(); i++)
	// {
	// 	std::cout << ' ' << bigS[i] << " " << bigS[i]->nb << " " << bigS[i]->rf.back();
	// 	std::cout << ' ' << bigS[i]->pos.back();
	// }
	// std::cout << std::endl;
	// for (size_t i = 0; i < Tiny.size(); i++)
	// {
	// 	std::cout << ' ' << Tiny[i] << " " << Tiny[i]->nb << " " << Tiny[i]->rf.back();
	// 	std::cout << ' ' << Tiny[i]->pos.back();
	// }
	// std::cout << std::endl;
	//swap Tiny
	Tiny = dequeReorderInGroups(Tiny);
	dequeAdjustPos(Tiny, 0);
	//binary search
	int	x;
	while(Tiny.size() > 0)
	{
		x = dequeBinarySearch(bigS, Tiny, 0);
		bigS.insert(bigS.begin()+x, Tiny[0]);
		Tiny.erase(Tiny.begin());
		bigS[x]->pos.pop_back();
		dequeAdjustPos(Tiny, 0);
		dequeAdjustPos(bigS, 0);
	}
	return bigS;
}

int	main (int argc, char **argv)
{
	if (error_handler(argc, argv) == 1)
		return 1;

	Numbers *nums = initializeNumbers(argc, argv);
	{
		// for (int i = 0; i < argc - 1; i++)
		// 	std::cout << ' ' << &nums[i];
		// std::cout << std::endl;
		// for (int i = 0; i < argc - 1; i++)
		// 	std::cout << nums[i].nb << "               " ;
		// std::cout << std::endl;
		// for (int i = 0; i < argc - 1; i++)
		// 	std::cout << ' ' << nums[i].rf.back();
		// std::cout << std::endl;
	}
	std::deque<Numbers*> deq;
	for (int i = 0; i < argc - 1; i++)
		deq.push_back(&nums[i]);
	for (size_t i = 0; i < deq.size(); i++)
	{
		//std::cout << ' ' << deq[i] << " ";
		std::cout << deq[i]->nb << " ";
		//std::cout << deq[i]->rf.back();
	}
	std::cout << std::endl;
	// deq = dequeReorderInGroups(deq);
	// for (size_t i = 0; i < deq.size(); i++)
	// {
	// 	//std::cout << ' ' << deq[i] << " ";
	// 	std::cout << deq[i]->nb << " ";
	// 	//std::cout << deq[i]->rf.back();
	// }
	// std::cout << std::endl;
	deq = dequeMergeSort(deq, argc - 1);
	for (size_t i = 0; i < deq.size(); i++)
	{
		//std::cout << ' ' << deq[i] << " ";
		std::cout << deq[i]->nb << " ";
		//std::cout << deq[i]->rf.back();
	}
	std::cout << std::endl;
	//for (int i = 0; i < argc - 1; i++)
	//{
	//	std::cout << ' ' << deq[i]->nb;
	//}
	//std::cout << std::endl;
	std::deque<int> done;

	for (size_t i = 0; i < deq.size(); i++)
	{
		//std::cout << ' ' << deq[i] << " ";
		done.push_back(deq[i]->nb);
		//std::cout << deq[i]->rf.back();
	}
	std::cout << std::endl;
	if (std::is_sorted(done.begin(), done.end()))
		std::cout << "LET'S FUCKING GO" << std::endl;
	else
		std::cout << "fuck" << std::endl;
	delete [] nums;
	return 0;
	// {
	// 	int max = 10;
	// 	int myints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// 	Numbers nums[max];
	// 	for (int i = 0; i < 10; i++)
	// 		nums[i].nb = myints[i];
	// 	for (int i = 0; i < 10; i++)
	// 	{
	// 		if (i % 2 == 0 && i + 1 < max)
	// 			nums[i].rf.push_back(&nums[i + 1]);
	// 		else if (i % 2 == 1)
	// 			nums[i].rf.push_back(&nums[i - 1]);
	// 		 else //nombre impair d'inputs, pas de paire pour le dernier input
	// 		 	nums[i].rf.push_back(NULL);
	// 	}
	// 	for (int i = 0; i < 10; i++)
	// 		std::cout << ' ' << &nums[i];
	// 	std::cout << std::endl;
	// 	for (int i = 0; i < 10; i++)
	// 		std::cout << nums[i].nb << "               " ;
	// 	std::cout << std::endl;
	// 	for (int i = 0; i < 10; i++)
	// 		std::cout << ' ' << nums[i].rf.back();
	// 	std::cout << std::endl;

	// 	for (int i = 0; i < 10; i++)
	// 		std::cout << ' ' << &nums[i];
	// 	std::cout << std::endl;
	// 	for (int i = 0; i < 10; i++)
	// 		std::cout << nums[i].nb << "               " ;
	// 	std::cout << std::endl;
	// 	for (int i = 0; i < 10; i++)
	// 		std::cout << ' ' << nums[i].rf.back();
	// 	std::cout << std::endl;

	// 	std::deque<Numbers*> deq;
	// 	for (int i = 0; i < 10; i++)
	// 		deq.push_back(&nums[i]);
	// 	for (int i = 0; i < 10; i++)
	// 		//std::cout << ' ' << deq[i].nb << deq[i].rf->nb;
	// 		std::cout << ' ' << deq[i]->nb << deq[i]->rf.back();
	// 	std::cout << std::endl;
	// 	std::iter_swap(deq.begin(), deq.begin()+3);
	// 	for (int i = 0; i < 10; i++)
	// 		//std::cout << ' ' << deq[i].nb << deq[i].rf->nb;
	// 		std::cout << ' ' << deq[i]->nb << deq[i]->rf.back();
	// 	std::cout << std::endl;
	// 	// for (int i = 0; i < 10; i++)
	// 	// {
	// 	// 	std::cout << &deq[i]->rf.back() << std::endl;
	// 	// 	std::cout << &nums[i].rf.back() << std::endl;
	// 	// }
	// 	for (std::deque<Numbers*>::iterator it = deq.begin(); it != deq.end(); ++it)
    //  	{
	//  		std::cout << ' ' << *it;
	//  	}
	// 	std::cout << std::endl;
	// 	for (std::deque<Numbers*>::iterator it = deq.begin(); *it != nums[0].rf.back(); ++it)
    //  	{
	//  		std::cout << ' ' << *it;
	//  	}
	// 	std::cout << std::endl;
	// 	////Tout ceci prouve que on peut stocker des références à nos nombres et les utiliser mais dans la recherche de l'iterator, on fait des comparaisons.... donc valide ou pas?
	// 	//Faire un while (it = deq.begin() != nums[0].rf.back()) { it++ et substring_size++ } comme ca on a la taille de la substring et on peut faire nos divs
	// }
	// {
	// 	int myints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// 	std::deque<int> deq(myints, myints+10);

  	// 	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    // 	{
	// 		std::cout << ' ' << &*it;
	// 	}
	// 	//std::cout << " " << deq.capacity() << std::endl;
	// 	//deq.push_back(10);
	// 	//std::cout << deq.capacity() << std::endl;
	// 	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    // 	{
	// 		std::cout << ' ' << &*it;
	// 	}
	// 	std::cout << std::endl;
	// 	int &b = deq[3];
	// 	std::cout << &deq[3] << "\n" << &b  << "\n"  << deq[3] << "\n" << b << std::endl;
	// 	//trouver un moyen de check si l'adresse de b correspond toujours au bon element en swapant les elements
	// 	std::iter_swap(deq.begin(), deq.begin()+3);
	// 	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    // 	{
	// 		std::cout << ' ' << &*it;
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << &deq[3] << "\n" << &b  << "\n"  << deq[3] << "\n" << b << std::endl;
	// 	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    // 	{
	// 		std::cout << ' ' << *it;
	// 	}
	// 	std::cout << std::endl;
	// }
	return 0;
}