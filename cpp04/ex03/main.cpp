#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
		//test sur les materias
	/*std::cout << std::endl << "-----------------MATERIA TEST :---------------" << std::endl << std::endl;

	std::cout << std::endl << "-----------------ICE CREATION AND ASSIGNATION :---------------" << std::endl << std::endl;
	Ice ice1 = Ice();
	Ice ice2 = Ice(ice1);
	Ice ice3 = Ice();
	ice3 = ice1;

	std::cout << std::endl << "-----------------ICE DISPLAY :---------------" << std::endl << std::endl;
	std::cout << ice1.getType() << std::endl;
	std::cout << ice2.getType() << std::endl;
	std::cout << ice3.getType() << std::endl;
	
	std::cout << std::endl << "-----------------CURE CREATION AND ASSIGNATION :---------------" << std::endl << std::endl;
	Cure cure1 = Cure();
	Cure cure2 = Cure(cure1);
	Cure cure3 = Cure();
	cure3 = cure1;

	std::cout << std::endl << "-----------------CURE DISPLAY :---------------" << std::endl << std::endl;
	std::cout << cure1.getType() << std::endl;
	std::cout << cure2.getType() << std::endl;
	std::cout << cure3.getType() << std::endl;

	std::cout << std::endl << "-----------------TARGET CREATION :---------------" << std::endl << std::endl;
	Character	target = Character("poor victim");

	std::cout << std::endl << "-----------------TARGET DISPLAY :---------------" << std::endl << std::endl;
	std::cout << target.getName() << std::endl;
	std::cout << target.getInventory(0) << std::endl;
	std::cout << target.getInventory(1) << std::endl;
	std::cout << target.getInventory(2) << std::endl;
	std::cout << target.getInventory(3) << std::endl;

	std::cout << std::endl << "-----------------MATERIA USE FUNCTION :---------------" << std::endl << std::endl;
	ice1.use(target);
	ice2.use(target);
	ice3.use(target);
	cure1.use(target);
	cure2.use(target);
	cure3.use(target);

	std::cout << std::endl << "-----------------MATERIA CLONE FUNCTION :---------------" << std::endl << std::endl;
	AMateria* copyice1;
	AMateria* copyice2;
	AMateria* copyice3;
	AMateria* copycure1;
	AMateria* copycure2;
	AMateria* copycure3;

	copyice1 = ice1.clone();
	copyice2 = ice2.clone();
	copyice3 = ice3.clone();
	copycure1 = cure1.clone();
	copycure2 = cure2.clone();
	copycure3 = cure3.clone();

	std::cout << std::endl << "-----------------MATERIA CLONE USE FUNCTION :---------------" << std::endl << std::endl;
	copyice1->use(target);
	copyice2->use(target);
	copyice3->use(target);
	copycure1->use(target);
	copycure2->use(target);
	copycure3->use(target);

	std::cout << std::endl << "-----------------MATERIA CLONE DELETION :---------------" << std::endl << std::endl;
	delete copyice1;
	delete copyice2;
	delete copyice3;
	delete copycure1;
	delete copycure2;
	delete copycure3;*/


















	//test sur materia source
	
	/*td::cout << std::endl << "-----------------MATERIA SOURCE TEST :---------------" << std::endl << std::endl;

	std::cout << std::endl << "-----------------CREATION MATERIA SOURCE :---------------" << std::endl << std::endl;
	MateriaSource*	src1 = new MateriaSource();
	MateriaSource*	src3 = new MateriaSource();
	
	std::cout << std::endl << "-----------------CREATION TARGET CHARACTER :---------------" << std::endl << std::endl;
	Character	target = Character("poor victim");

	std::cout << std::endl << "-----------------TARGET DISPLAY :---------------" << std::endl << std::endl;
	std::cout << target.getName() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << target.getInventory(i) << std::endl;
	}

	std::cout << std::endl << "-----------------CREATION MATERIA :---------------" << std::endl << std::endl;
	AMateria*		ice = new Ice();
	AMateria*		cure = new Cure();

	std::cout << std::endl << "-----------------FUNCTION LEARN TEST :---------------" << std::endl << std::endl;
	src1->learnMateria(ice);
	src1->learnMateria(ice);

	std::cout << std::endl << "-----------------COPY CONSTRUCTOR TEST :---------------" << std::endl << std::endl;
	MateriaSource*	src2 = new MateriaSource(*src1);

	std::cout << std::endl << "-----------------FUNCTION LEARN TEST :---------------" << std::endl << std::endl;
	src1->learnMateria(cure);

	std::cout << std::endl << "-----------------ASSIGNMENT TEST :---------------" << std::endl << std::endl;
	*src3 = *src1;

	std::cout << std::endl << "-----------------FUNCTION LEARN TEST :---------------" << std::endl << std::endl;
	src1->learnMateria(cure);
	src1->learnMateria(cure);
	src3->learnMateria(ice);

	std::cout << std::endl << "-----------------DISPLAY MATERIA SOURCE CONTENT :---------------" << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src1->getInventory(i) != NULL)
			std::cout << "1 " << src1->getInventory(i)->getType() << std::endl;
		if (src2->getInventory(i) != NULL)
			std::cout << "2 " << src2->getInventory(i)->getType() << std::endl;
		if (src3->getInventory(i) != NULL)
			std::cout << "3 " << src3->getInventory(i)->getType() << std::endl;
	}

	std::cout << std::endl << "-----------------FUNCTION CREATE TEST :---------------" << std::endl << std::endl;
	AMateria* tmp;

	std::cout << std::endl << "-----------------FUNCTION CREATE SRC1 :---------------" << std::endl << std::endl;
	tmp = src1->createMateria("ice");
	if (tmp)
		tmp->use(target);
	delete tmp;
	tmp = src1->createMateria("cure");
	if (tmp)
		tmp->use(target);
	delete tmp;
	tmp = src1->createMateria("Cure");
	if (tmp)
		tmp->use(target);
	delete tmp;

	std::cout << std::endl << "-----------------FUNCTION CREATE SRC2 :---------------" << std::endl << std::endl;
	tmp = src2->createMateria("ice");
	if (tmp)
		tmp->use(target);
	delete tmp;
	tmp = src2->createMateria("cure");
	if (tmp)
		tmp->use(target);
	delete tmp;
	tmp = src2->createMateria("Cure");
	if (tmp)
		tmp->use(target);
	delete tmp;

	std::cout << std::endl << "-----------------FUNCTION CREATE SRC3 :---------------" << std::endl << std::endl;
	tmp = src3->createMateria("ice");
	if (tmp)
		tmp->use(target);
	delete tmp;
	tmp = src3->createMateria("cure");
	if (tmp)
		tmp->use(target);
	delete tmp;
	tmp = src3->createMateria("Cure");
	if (tmp)
		tmp->use(target);
	delete tmp;

	std::cout << "-----------------CLEAN UP---------------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src1->getInventory(i) != NULL)
			std::cout << "1 " << src1->getInventory(i)->getType() << " " << src1->getInventory(i) << std::endl;
		if (src2->getInventory(i) != NULL)
			std::cout << "2 " << src2->getInventory(i)->getType() << " " << src2->getInventory(i) << std::endl;
		if (src3->getInventory(i) != NULL)
			std::cout << "3 " << src3->getInventory(i)->getType() << " " << src3->getInventory(i) << std::endl;
	}
	delete src1;
	delete src2;
	delete src3;
	delete ice;
	delete cure;*/




















	
	//test sur Character
	/* std::cout << std::endl << "-----------------CHARACTER TEST :---------------" << std::endl << std::endl;
 
	std::cout << std::endl << "-----------------CREATION CHARACTER TEST :---------------" << std::endl << std::endl;
	Character	character1 = Character();
	Character	character2 = Character("poor victim");
	Character	character3 = Character();

	std::cout << std::endl << "-----------------CREATION MATERIA SOURCE :---------------" << std::endl << std::endl;
	MateriaSource*	src = new MateriaSource();

	std::cout << std::endl << "-----------------CREATION MATERIA :---------------" << std::endl << std::endl;
	AMateria*		ice = new Ice();
	AMateria*		cure = new Cure();

	std::cout << std::endl << "-----------------LEARNING MATERIA :---------------" << std::endl << std::endl;
	src->learnMateria(ice);
	src->learnMateria(cure);
	
	std::cout << std::endl << "-----------------DISPLAY MATERIA SOURCE :---------------" << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src->getInventory(i) != NULL)
			std::cout << "1 " << src->getInventory(i)->getType() << std::endl;
	}

	std::cout << std::endl << "-----------------DISPLAY CHARACTER :---------------" << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (character1.getInventory(i) != NULL)
			std::cout << character1.getName() << character1.getInventory(i)->getType() << std::endl;
		if (character2.getInventory(i) != NULL)
			std::cout << character2.getName() << character2.getInventory(i)->getType() << std::endl;
		if (character3.getInventory(i) != NULL)
			std::cout << character3.getName() << character3.getInventory(i)->getType() << std::endl;
	}
	
	std::cout << std::endl << "-----------------EQUIPE TEST :---------------" << std::endl << std::endl;
	AMateria*	tmp;

	tmp = src->createMateria("ice");
	if (tmp)
		character1.equip(tmp);
	delete(tmp);
	tmp = src->createMateria("ice");
	if (tmp)
		character1.equip(tmp);
	delete (tmp);

	std::cout << std::endl << "-----------------COPY CONSTRUCTOR TEST :---------------" << std::endl << std::endl;
	Character	character4 = Character(character1);

	std::cout << std::endl << "-----------------EQUIP TEST :---------------" << std::endl << std::endl;
	tmp = src->createMateria("cure");
	if (tmp)
		character1.equip(tmp);
	delete (tmp);
	tmp = src->createMateria("Cce");
	if (tmp)
		character1.equip(tmp);
	delete (tmp);

	std::cout << std::endl << "-----------------ASSIGNATION TEST :---------------" << std::endl << std::endl;
	character3 = character1;

	std::cout << std::endl << "-----------------EQUIP TEST :---------------" << std::endl << std::endl;
	tmp = src->createMateria("cure");
	if (tmp)
		character1.equip(tmp);
	delete tmp;
	tmp = src->createMateria("ice");
	if (tmp)
		character3.equip(tmp);
	delete tmp;
	
	std::cout << std::endl << "-----------------DISPLAY CHARACTER :---------------" << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (character1.getInventory(i) != NULL)
			std::cout << character1.getName() << character1.getInventory(i)->getType() << std::endl;
		if (character2.getInventory(i) != NULL)
			std::cout << character2.getName() << character2.getInventory(i)->getType() << std::endl;
		if (character3.getInventory(i) != NULL)
			std::cout << character3.getName() << character3.getInventory(i)->getType() << std::endl;
		if (character4.getInventory(i) != NULL)
			std::cout << character4.getName() << character4.getInventory(i)->getType() << std::endl;
	}

	std::cout << std::endl << "-----------------USE TEST :---------------" << std::endl << std::endl;

	std::cout << std::endl << "-----------------character 1 USE TEST :---------------" << std::endl << std::endl;
	character1.use(0, character2);
	character1.use(1, character2);
	character1.use(2, character2);
	character1.use(3, character2);
	character1.use(4, character2);
	character1.use(-1, character2);

	std::cout << std::endl << "-----------------character 2 USE TEST :---------------" << std::endl << std::endl;
	character2.use(0, character2);
	character2.use(1, character2);
	character2.use(2, character2);
	character2.use(3, character2);
	character2.use(4, character2);
	character2.use(-1, character2);

	std::cout << std::endl << "-----------------character 3 USE TEST :---------------" << std::endl << std::endl;
	character3.use(0, character2);
	character3.use(1, character2);
	character3.use(2, character2);
	character3.use(3, character2);
	character3.use(4, character2);
	character3.use(-1, character2);

	std::cout << std::endl << "-----------------character 4 USE TEST :---------------" << std::endl << std::endl;
	character4.use(0, character2);
	character4.use(1, character2);
	character4.use(2, character2);
	character4.use(3, character2);
	character4.use(4, character2);
	character4.use(-1, character2);

	std::cout << std::endl << "-----------------DISPLAY CHARACTER :---------------" << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (character1.getInventory(i) != NULL)
			std::cout << character1.getName() << character1.getInventory(i)->getType() << std::endl;
		if (character2.getInventory(i) != NULL)
			std::cout << character2.getName() << character2.getInventory(i)->getType() << std::endl;
		if (character3.getInventory(i) != NULL)
			std::cout << character3.getName() << character3.getInventory(i)->getType() << std::endl;
		if (character4.getInventory(i) != NULL)
			std::cout << character4.getName() << character4.getInventory(i)->getType() << std::endl;
	}

	std::cout << std::endl << "-----------------character 1 UNEQUIP TEST :---------------" << std::endl << std::endl;
	character1.unequip(0);
	character1.unequip(1);
	character1.unequip(2);
	character1.unequip(3);
	character1.unequip(4);
	character1.unequip(-1);

	std::cout << std::endl << "-----------------character 2 UNEQUIP TEST :---------------" << std::endl << std::endl;
	character2.unequip(0);
	character2.unequip(1);
	character2.unequip(2);
	character2.unequip(3);
	character2.unequip(4);
	character2.unequip(-1);

	std::cout << std::endl << "-----------------character 3 UNEQUIP TEST :---------------" << std::endl << std::endl;
	character3.unequip(0);
	character3.unequip(1);
	character3.unequip(2);
	character3.unequip(3);
	character3.unequip(4);
	character3.unequip(-1);

	std::cout << std::endl << "-----------------character 4 UNEQUIP TEST :---------------" << std::endl << std::endl;
	character4.unequip(0);
	character4.unequip(1);
	character4.unequip(2);
	character4.unequip(3);
	character4.unequip(4);
	character4.unequip(-1);

	std::cout << std::endl << "-----------------character 1 ADDITIONAL UNEQUIP TEST :---------------" << std::endl << std::endl;
	tmp = src->createMateria("ice");
	if (tmp)
		character1.equip(tmp);
	delete tmp;
	tmp = src->createMateria("ice");
	if (tmp)
		character1.equip(tmp);
	delete tmp;
	character1.unequip(1);
	character1.unequip(2);
	character1.unequip(3);
	character1.unequip(4);
	character1.unequip(-1);

	std::cout << std::endl << "-----------------CLEANUP MAIN (MATERIA SOURCE AND BASE MATERIA) :---------------" << std::endl << std::endl;
	delete src;
	delete ice;
	delete cure;

	std::cout << "-----------------DESTRUCTION CALL---------------" << std::endl;*/
	/*MateriaSource src = MateriaSource();
	AMateria *ice = new Ice();
	src.learnMateria(ice);
	AMateria *cure = new Cure();
	src.learnMateria(cure);
	Character* me = new Character("me");
	me->equip(ice);
	AMateria* tmp;
	tmp = src.createMateria("ice");
	me->equip(tmp);
	delete tmp;
	tmp = src.createMateria("cure");
	me->equip(tmp);
	delete tmp;
	ICharacter* bob = new Character("bob");
	bob->equip(ice);
	*bob = *me;
	bob->unequip(0);
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete ice;
	delete cure;*/

	IMateriaSource* src = new MateriaSource();
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
	delete src;
	
	return 0;
}