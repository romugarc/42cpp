/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 06:53:49 by rgarcia           #+#    #+#             */
/*   Updated: 2023/11/09 06:53:53 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main (int argc, char **argv)
{
	if (error_handler(argc, argv) == 1)
		return 1;

	std::cout << "-------------Deque---------------" << std::endl;
	clock_t	start, end;
	double cpu_time_used;

	start = clock();
	NumbersDeq *nums = initializeNumbersDeq(argc, argv);
	std::deque<NumbersDeq*> deq;
	
	for (int i = 0; i < argc - 1; i++)
		deq.push_back(&nums[i]);
	
	std::cout << "Before: ";
	for (size_t i = 0; i < deq.size(); i++)
		std::cout << deq[i]->nb << " ";
	std::cout << std::endl;
	
	deq = mergeSort(deq, argc - 1);
	end = clock();
	cpu_time_used = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
	
	std::cout << "After: ";
	for (size_t i = 0; i < deq.size(); i++)
		std::cout << deq[i]->nb << " ";
	std::cout << std::endl;

	std::cout << "Time used to sort " << deq.size() << " elements with deque: " << cpu_time_used << " ms" << std::endl;

	delete [] nums;

	std::cout << "-------------Vector---------------" << std::endl;
	clock_t	startv, endv;
	double cpu_time_usedv;

	startv = clock();
	NumbersVec *numsv = initializeNumbersVec(argc, argv);
	std::vector<NumbersVec*> vec;
	
	for (int i = 0; i < argc - 1; i++)
		vec.push_back(&numsv[i]);

	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i]->nb << " ";
	std::cout << std::endl;
	
	vec = mergeSort(vec, argc - 1);
	endv = clock();
	cpu_time_usedv = ((double) (endv - startv)) * 1000 / CLOCKS_PER_SEC;
	
	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i]->nb << " ";
	std::cout << std::endl;

	std::cout << "Time used to sort " << vec.size() << " elements with vector: " << cpu_time_usedv << " ms" << std::endl;

	delete [] numsv;
	return 0;
}
