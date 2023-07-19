#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::complain( std::string level ) const {
	void		(Harl::*f[4])(void) const;
	const char	*listlevels[4];
	int	i = 0;

	listlevels[0] = "DEBUG";
	f[0] = &Harl::debug;
	listlevels[1] = "INFO";
	f[1] = &Harl::info;
	listlevels[2] = "WARNING";
	f[2] = &Harl::warning;
	listlevels[3] = "ERROR";
	f[3] = &Harl::error;

	while (i < 4)
	{
		if (listlevels[i] == level)
			(this->*f[i])();
		i++;
	}
}

void	Harl::debug( void ) const {
	std::cout << "This is the DEBUG message" << std::endl;
}

void	Harl::info( void ) const {
	std::cout << "This is the INFO message" << std::endl;
}

void	Harl::warning( void ) const {
	std::cout << "This is a WARNING message" << std::endl;
}

void	Harl::error( void ) const {
	std::cout << "There was an ERROR and this is the message << std::endl;" << std::endl;
}