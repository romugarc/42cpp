#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();
	AMateria *ice = new Ice();
	src->learnMateria(ice);
	AMateria *cure = new Cure();
	src->learnMateria(cure);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	delete ice;
	delete cure;

	std::cout << "-------ADDITIONAL TESTS--------" << std::endl;
	MateriaSource *nsrc = new MateriaSource();
	AMateria *ice2 = new Ice();
	nsrc->learnMateria(ice2);
	AMateria *cure2 = new Cure();
	nsrc->learnMateria(cure2);
	nsrc->learnMateria(ice2);
	nsrc->learnMateria(cure2);
	AMateria *ice3 = new Ice();
	nsrc->learnMateria(ice3);
	AMateria *cure3 = new Cure();
	nsrc->learnMateria(cure3);
	std::cout << std::endl << "--------NSRC INVENTORY--------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (nsrc->getInventory(i) != NULL)
			std::cout << i << " " << nsrc->getInventory(i)->getType() << " " << nsrc->getInventory(i) << std::endl;
	}
	MateriaSource *csrc = new MateriaSource(*nsrc);
	std::cout << std::endl << "--------CSRC INVENTORY--------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (csrc->getInventory(i) != NULL)
			std::cout << i << " " << csrc->getInventory(i)->getType() << " " << csrc->getInventory(i) << std::endl;
	}
	Character noname = Character();
	AMateria* tmpn;
	tmpn = nsrc->createMateria("ice");
	noname.equip(tmpn);
	delete tmpn;
	tmpn = nsrc->createMateria("cure");
	noname.equip(tmpn);
	delete tmpn;
	tmpn = nsrc->createMateria("Fire");
	noname.equip(tmpn);
	delete tmpn;
	tmpn = nsrc->createMateria("Fire");
	noname.equip(tmpn);
	delete tmpn;
	tmpn = nsrc->createMateria("ice");
	noname.equip(tmpn);
	delete tmpn;
	tmpn = nsrc->createMateria("cure");
	noname.equip(tmpn);
	delete tmpn;
	tmpn = nsrc->createMateria("cure");
	noname.equip(tmpn);
	delete tmpn;
	std::cout << std::endl << "--------NONAME INVENTORY--------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (noname.getInventory(i) != NULL)
			std::cout << noname.getName() << " " << i << " "  << noname.getInventory(i)->getType() << " " << noname.getInventory(i) << std::endl;
	}
	Character* marc = new Character("marc");
	std::cout << std::endl << "--------NONAME USE MATERIA--------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		noname.use(i, *marc);
	}
	marc->equip(ice2);
	marc->equip(cure2);
	std::cout << std::endl << "--------MARC INVENTORY--------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (marc->getInventory(i) != NULL)
			std::cout << marc->getName() << " " << i << " "  << marc->getInventory(i)->getType() << " " << marc->getInventory(i) << std::endl;
	}
	std::cout << std::endl << "--------MARC USE MATERIA--------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		marc->use(i, noname);
	}
	std::cout << std::endl << "--------MARC = NONAME--------" << std::endl;
	*marc = noname;
	std::cout << std::endl << "--------MARC INVENTORY--------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (marc->getInventory(i) != NULL)
			std::cout << marc->getName() << " " << i << " "  << marc->getInventory(i)->getType() << " " << marc->getInventory(i) << std::endl;
	}
	marc->unequip(2);
	for (int i = 0; i < 4; i++)
	{
		if (marc->getInventory(i) != NULL)
			std::cout << marc->getName() << " " << i << " "  << marc->getInventory(i)->getType() << " " << marc->getInventory(i) << std::endl;
	}
	marc->equip(cure2);
	for (int i = 0; i < 4; i++)
	{
		if (marc->getInventory(i) != NULL)
			std::cout << marc->getName() << " " << i << " "  << marc->getInventory(i)->getType() << " " << marc->getInventory(i) << std::endl;
	}
	std::cout << std::endl << "--------MARC USE MATERIA--------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		marc->use(i, noname);
	}
	std::cout << std::endl << "--------NONAME INVENTORY--------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (noname.getInventory(i) != NULL)
			std::cout << noname.getName() << " " << i << " "  << noname.getInventory(i)->getType() << " " << noname.getInventory(i) << std::endl;
	}
	delete marc;
	delete nsrc;
	delete csrc;
	delete ice2;
	delete cure2;
	delete ice3;
	delete cure3;

	/*IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;*/
	
	return 0;
}