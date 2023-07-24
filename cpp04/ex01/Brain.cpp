#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain default constructor called" << std::endl;
	return;
}

Brain::Brain( Brain const &src ) {
	unsigned int	i;

	std::cout << "Brain copy constructor called" << std::endl;
	i = 0;
	while (i < 100)
	{
		this->setIdeas(i, src.getIdeas(i));
		i++;
	}
	return;
}

std::string	Brain::getIdeas( unsigned int n ) const {
	if (n >= 100)
	{
		std::string incorrect = "";
		std::cout << "Index value must be from 0 to 99" << std::endl;
		return incorrect;
	}
	return this->_ideas[n];
}

void	Brain::setIdeas( unsigned int n, std::string idea ) {
	if (n >= 100)
	{
		std::cout << "Index value must be from 0 to 99" << std::endl;
		return;
	}
	while (n < 100)
	{
		this->_ideas[n] = idea;
		n++;
	}
	return;
}

Brain	&Brain::operator=( Brain const &rhs ) {
	unsigned int	i;

	if (this != &rhs)
	{
		i = 0;
		while (i < 100)
		{
			this->setIdeas(i, rhs.getIdeas(i));
			i++;
		}
	}
	return *this;
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor called" << std::endl;
	return;
}