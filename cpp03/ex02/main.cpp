/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:06:15 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 09:06:38 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::string name = "sauce";
	FragTrap	c1;
	FragTrap	c2(c1);
	FragTrap	c3(name);

	c3.takeDamage(10);
	c1 = c3;

	std::cout << "display des stats : " << std::endl << 
	"name : " << c1.getName() << std::endl << 
	"life : " << c1.getHitPoints() << std::endl << 
	"energy : " << c1.getEnergyPoints() << std::endl << 
	"attack damage : " << c1.getAttackDamage() << std::endl << std::endl;
	std::cout << "display des stats : " << std::endl << 
	"name : " << c2.getName() << std::endl << 
	"life : " << c2.getHitPoints() << std::endl << 
	"energy : " << c2.getEnergyPoints() << std::endl << 
	"attack damage : " << c2.getAttackDamage() << std::endl << std::endl;
	std::cout << "display des stats : " << std::endl << 
	"name : " << c3.getName() << std::endl << 
	"life : " << c3.getHitPoints() << std::endl << 
	"energy : " << c3.getEnergyPoints() << std::endl << 
	"attack damage : " << c3.getAttackDamage() << std::endl << std::endl;

	// c1
	std::cout << "-------------" << std::endl;
	std::cout << "energy : " << c1.getEnergyPoints() << std::endl << "life : " << c1.getHitPoints() << std::endl;
	c1.attack("chicken");
	std::cout << "Chicken attacks !" << std::endl;
	c1.takeDamage(1);
	std::cout << "energy : " << c1.getEnergyPoints() << std::endl << "life : " << c1.getHitPoints() << std::endl;
	c1.beRepaired(10);
	std::cout << "energy : " << c1.getEnergyPoints() << std::endl << "life : " << c1.getHitPoints() << std::endl;
	c1.highFivesGuys();
	std::cout << "energy : " << c1.getEnergyPoints() << std::endl << "life : " << c1.getHitPoints() << std::endl;
	std::cout << "Chicken uses an EMP ! " << c1.getName() << " loses all of its EnergyPoints !" << std::endl;
	c1.setEnergyPoints(0);
	std::cout << "energy : " << c1.getEnergyPoints() << std::endl << "life : " << c1.getHitPoints() << std::endl;
	c1.attack("chicken");
	std::cout << "Chicken attacks !" << std::endl;
	c1.takeDamage(1);
	std::cout << "energy : " << c1.getEnergyPoints() << std::endl << "life : " << c1.getHitPoints() << std::endl;
	c1.beRepaired(10);
	std::cout << "energy : " << c1.getEnergyPoints() << std::endl << "life : " << c1.getHitPoints() << std::endl;
	c1.highFivesGuys();
	std::cout << "energy : " << c1.getEnergyPoints() << std::endl << "life : " << c1.getHitPoints() << std::endl;
	std::cout << c1.getName() << " finds a new battery and recovers all of its energy !" << std::endl;
	c1.setEnergyPoints(10);
	std::cout << "energy : " << c1.getEnergyPoints() << std::endl << "life : " << c1.getHitPoints() << std::endl;
	std::cout << "Chicken uses a tactical nuke !" << std::endl;
	c1.takeDamage(9999);
	std::cout << "energy : " << c1.getEnergyPoints() << std::endl << "life : " << c1.getHitPoints() << std::endl;
	c1.attack("chicken");
	c1.beRepaired(1000);
	c1.highFivesGuys();
	std::cout << "Chicken attacks !" << std::endl;
	c1.takeDamage(1);
	std::cout << "energy : " << c1.getEnergyPoints() << std::endl << "life : " << c1.getHitPoints() << std::endl;
	std::cout << "--------------------" << std::endl << std::endl;

	// c2
	std::cout << "-------------" << std::endl;
	std::cout << "energy : " << c2.getEnergyPoints() << std::endl << "life : " << c2.getHitPoints() << std::endl;
	c2.attack("chicken");
	std::cout << "Chicken attacks !" << std::endl;
	c2.takeDamage(1);
	std::cout << "energy : " << c2.getEnergyPoints() << std::endl << "life : " << c2.getHitPoints() << std::endl;
	c2.beRepaired(10);
	std::cout << "energy : " << c2.getEnergyPoints() << std::endl << "life : " << c2.getHitPoints() << std::endl;
	c2.highFivesGuys();
	std::cout << "energy : " << c2.getEnergyPoints() << std::endl << "life : " << c2.getHitPoints() << std::endl;
	std::cout << "Chicken uses an EMP ! " << c2.getName() << " loses all of its EnergyPoints !" << std::endl;
	c2.setEnergyPoints(0);
	std::cout << "energy : " << c2.getEnergyPoints() << std::endl << "life : " << c2.getHitPoints() << std::endl;
	c2.attack("chicken");
	std::cout << "Chicken attacks !" << std::endl;
	c2.takeDamage(1);
	std::cout << "energy : " << c2.getEnergyPoints() << std::endl << "life : " << c2.getHitPoints() << std::endl;
	c2.beRepaired(10);
	std::cout << "energy : " << c2.getEnergyPoints() << std::endl << "life : " << c2.getHitPoints() << std::endl;
	c2.highFivesGuys();
	std::cout << "energy : " << c2.getEnergyPoints() << std::endl << "life : " << c2.getHitPoints() << std::endl;
	std::cout << c2.getName() << " finds a new battery and recovers all of its energy !" << std::endl;
	c2.setEnergyPoints(10);
	std::cout << "energy : " << c2.getEnergyPoints() << std::endl << "life : " << c2.getHitPoints() << std::endl;
	std::cout << "Chicken uses a tactical nuke !" << std::endl;
	c2.takeDamage(9999);
	std::cout << "energy : " << c2.getEnergyPoints() << std::endl << "life : " << c2.getHitPoints() << std::endl;
	c2.attack("chicken");
	c2.beRepaired(1000);
	c2.highFivesGuys();
	std::cout << "Chicken attacks !" << std::endl;
	c2.takeDamage(1);
	std::cout << "energy : " << c2.getEnergyPoints() << std::endl << "life : " << c2.getHitPoints() << std::endl;
	std::cout << "--------------------" << std::endl << std::endl;

	// c3
	std::cout << "-------------" << std::endl;
	std::cout << c3.getName() << " wants to change its name, so it is now called pasta" << std::endl;
	c3.setName("pasta");
	std::cout << "energy : " << c3.getEnergyPoints() << std::endl << "life : " << c3.getHitPoints() << std::endl;
	c3.attack("chicken");
	std::cout << "Chicken attacks !" << std::endl;
	c3.takeDamage(1);
	std::cout << "energy : " << c3.getEnergyPoints() << std::endl << "life : " << c3.getHitPoints() << std::endl;
	c3.beRepaired(10);
	std::cout << "energy : " << c3.getEnergyPoints() << std::endl << "life : " << c3.getHitPoints() << std::endl;
	c3.highFivesGuys();
	std::cout << "energy : " << c3.getEnergyPoints() << std::endl << "life : " << c3.getHitPoints() << std::endl;
	std::cout << "Chicken uses an EMP ! " << c3.getName() << " loses all of its EnergyPoints !" << std::endl;
	c3.setEnergyPoints(0);
	std::cout << "energy : " << c3.getEnergyPoints() << std::endl << "life : " << c3.getHitPoints() << std::endl;
	c3.attack("chicken");
	std::cout << "Chicken attacks !" << std::endl;
	c3.takeDamage(1);
	std::cout << "energy : " << c3.getEnergyPoints() << std::endl << "life : " << c3.getHitPoints() << std::endl;
	c3.beRepaired(10);
	std::cout << "energy : " << c3.getEnergyPoints() << std::endl << "life : " << c3.getHitPoints() << std::endl;
	c3.highFivesGuys();
	std::cout << "energy : " << c3.getEnergyPoints() << std::endl << "life : " << c3.getHitPoints() << std::endl;
	std::cout << c3.getName() << " finds a new battery and recovers all of its energy !" << std::endl;
	c3.setEnergyPoints(10);
	std::cout << "energy : " << c3.getEnergyPoints() << std::endl << "life : " << c3.getHitPoints() << std::endl;
	std::cout << "Chicken uses a tactical nuke !" << std::endl;
	c3.takeDamage(9999);
	std::cout << "energy : " << c3.getEnergyPoints() << std::endl << "life : " << c3.getHitPoints() << std::endl;
	c3.attack("chicken");
	c3.beRepaired(1000);
	c3.highFivesGuys();
	std::cout << "Chicken attacks !" << std::endl;
	c3.takeDamage(1);
	std::cout << "energy : " << c3.getEnergyPoints() << std::endl << "life : " << c3.getHitPoints() << std::endl;
	std::cout << "--------------------" << std::endl << std::endl;
	return 0;
}
