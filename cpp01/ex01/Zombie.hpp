#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <memory>

class Zombie {
	private:
		std::string	_name;
	public:
		Zombie();
		~Zombie();

		std::string	getName() const;

		void	setName(std::string name);
		void	announce(void) const;
};

Zombie*	zombieHorde(int N, std::string name);

#endif