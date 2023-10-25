/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:38:35 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/24 17:38:41 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main ( void )
{
	{
		std::cout << "------------MutantStack sujet---------------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "\n--MutantStack copie:" << std::endl;
		std::cout << &mstack << std::endl;
		std::cout << &s << std::endl;
		std::cout << "s.pop() used here" << std::endl;
		s.pop();
		std::cout << "stack size: " << mstack.size() << std::endl;
		std::cout << "s size: " << s.size() << std::endl;
	}

	{
		std::cout << "-----------------Comparaison output std::stack-------------" << std::endl;
		std::stack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		while(!mstack.empty()) {
		    std::cout << mstack.top() << std::endl;
		    mstack.pop();
		}
	}

	{
		std::cout << "-------------------Comparaison output std::list-------------" << std::endl;
		std::list<int> mstack;
		mstack.push_front(5);
		mstack.push_front(17);
		std::cout << mstack.front() << std::endl;
		mstack.pop_front();
		std::cout << mstack.size() << std::endl;
		mstack.push_front(3);
		mstack.push_front(5);
		mstack.push_front(737);
		mstack.push_front(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}