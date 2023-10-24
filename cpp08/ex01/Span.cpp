/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:40:53 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/20 17:40:54 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) {
}

Span::Span( unsigned int N ) {
	this->container.reserve(N);
}

Span::Span( Span const &src ) {
	this->container.reserve(src.container.capacity());
	for (size_t i = 0; i < src.container.size(); i++)
		this->container[i] = src.container[i];
}

Span::~Span() {
	this->container.clear();
}

Span	&Span::operator=( Span const &rhs ) {
	this->container.resize(rhs.container.size());
	for (size_t i = 0; i < rhs.container.size(); i++)
		this->container[i] = rhs.container[i];
	return *this;
}

void	Span::getContainer( void ) const {
	std::cout << "container: ";
	for (size_t i = 0; i < this->container.size(); i++)
		std::cout << this->container[i] << " ";
	std::cout << std::endl;
}

void	Span::addNumber( int nb ) {
	if (this->container.size() < this->container.capacity())
		this->container.push_back(nb);
	else
		throw ContainerFullException();
}

void	Span::addMoreNumbers( int *tab, int tabsize ) {
	for (int i = 0; i < tabsize; i++)
		addNumber(tab[i]);
}

int	Span::shortestSpan( void ) const {
	int shortest;
	std::vector<int> tmp;

	if (this->container.size() < 2)
		throw NotEnoughValuesException();
	tmp = this->container;
	std::sort(tmp.begin(), tmp.end());
	shortest = tmp[1] - tmp[0];
	for (size_t i = 0; i < tmp.size(); i++)
	{
		for (size_t j = i + 1; j < tmp.size(); j++)
		{
			if (tmp[j] - tmp[i] < shortest)
				shortest = tmp[j] - tmp[i];
		}
	}
	tmp.clear();
	return (shortest);
}

int	Span::longestSpan( void ) const {
	if (container.size() < 2)
		throw NotEnoughValuesException();
	return (*std::max_element(this->container.begin(), this->container.end()) - *std::min_element(this->container.begin(), this->container.end()));
}