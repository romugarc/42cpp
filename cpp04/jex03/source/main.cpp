/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warnora <warnora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:59:16 by jrinna            #+#    #+#             */
/*   Updated: 2023/09/06 08:30:18 by warnora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main( void ) {

	//test sur les materias
	/*cout << endl << "-----------------MATERIA TEST :---------------" << endl << endl;

	cout << endl << "-----------------ICE CREATION AND ASSIGNATION :---------------" << endl << endl;
	Ice ice1 = Ice();
	Ice ice2 = Ice(ice1);
	Ice ice3 = Ice();
	ice3 = ice1;

	cout << endl << "-----------------ICE DISPLAY :---------------" << endl << endl;
	cout << ice1 << endl;
	cout << ice2 << endl;
	cout << ice3 << endl;
	
	cout << endl << "-----------------CURE CREATION AND ASSIGNATION :---------------" << endl << endl;
	Cure cure1 = Cure();
	Cure cure2 = Cure(cure1);
	Cure cure3 = Cure();
	cure3 = cure1;

	cout << endl << "-----------------CURE DISPLAY :---------------" << endl << endl;
	cout << cure1 << endl;
	cout << cure2 << endl;
	cout << cure3 << endl;

	cout << endl << "-----------------TARGET CREATION :---------------" << endl << endl;
	Character	target = Character("poor victim");

	cout << endl << "-----------------TARGET DISPLAY :---------------" << endl << endl;
	cout << target << endl;

	cout << endl << "-----------------MATERIA USE FUNCTION :---------------" << endl << endl;
	ice1.use(target);
	ice2.use(target);
	ice3.use(target);
	cure1.use(target);
	cure2.use(target);
	cure3.use(target);

	cout << endl << "-----------------MATERIA CLONE FUNCTION :---------------" << endl << endl;
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

	cout << endl << "-----------------MATERIA CLONE USE FUNCTION :---------------" << endl << endl;
	copyice1->use(target);
	copyice2->use(target);
	copyice3->use(target);
	copycure1->use(target);
	copycure2->use(target);
	copycure3->use(target);

	cout << endl << "-----------------MATERIA CLONE DELETION :---------------" << endl << endl;
	delete copyice1;
	delete copyice2;
	delete copyice3;
	delete copycure1;
	delete copycure2;
	delete copycure3;*/


















	//test sur materia source
	
	 cout << endl << "-----------------MATERIA SOURCE TEST :---------------" << endl << endl;

	cout << endl << "-----------------CREATION MATERIA SOURCE :---------------" << endl << endl;
	MateriaSource*	src1 = new MateriaSource();
	MateriaSource*	src3 = new MateriaSource();
	
	cout << endl << "-----------------CREATION TARGET CHARACTER :---------------" << endl << endl;
	Character	target = Character("poor victim");

	cout << endl << "-----------------TARGET DISPLAY :---------------" << endl << endl;
	cout << target << endl;

	cout << endl << "-----------------CREATION MATERIA :---------------" << endl << endl;
	AMateria*		ice = new Ice();
	AMateria*		cure = new Cure();

	cout << endl << "-----------------FUNCTION LEARN TEST :---------------" << endl << endl;
	src1->learnMateria(ice);
	src1->learnMateria(ice);

	cout << endl << "-----------------COPY CONSTRUCTOR TEST :---------------" << endl << endl;
	MateriaSource*	src2 = new MateriaSource(*src1);

	cout << endl << "-----------------FUNCTION LEARN TEST :---------------" << endl << endl;
	src1->learnMateria(cure);

	cout << endl << "-----------------ASSIGNMENT TEST :---------------" << endl << endl;
	*src3 = *src1;

	cout << endl << "-----------------FUNCTION LEARN TEST :---------------" << endl << endl;
	src1->learnMateria(cure);
	src1->learnMateria(cure);
	src3->learnMateria(ice);

	cout << endl << "-----------------DISPLAY MATERIA SOURCE CONTENT :---------------" << endl << endl;
	cout << *src1 << endl;
	cout << *src2 << endl;
	cout << *src3 << endl;

	cout << endl << "-----------------FUNCTION CREATE TEST :---------------" << endl << endl;
	AMateria* tmp;

	cout << endl << "-----------------FUNCTION CREATE SRC1 :---------------" << endl << endl;
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

	cout << endl << "-----------------FUNCTION CREATE SRC2 :---------------" << endl << endl;
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

	cout << endl << "-----------------FUNCTION CREATE SRC3 :---------------" << endl << endl;
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

	cout << "-----------------CLEAN UP---------------" << endl;
	delete src1;
	delete src2;
	delete src3;
	delete ice;
	delete cure;




















	
	//test sur Character
	/* cout << endl << "-----------------CHARACTER TEST :---------------" << endl << endl;
 
	cout << endl << "-----------------CREATION CHARACTER TEST :---------------" << endl << endl;
	Character	character1 = Character();
	Character	character2 = Character("poor victim");
	Character	character3 = Character();

	cout << endl << "-----------------CREATION MATERIA SOURCE :---------------" << endl << endl;
	MateriaSource*	src = new MateriaSource();

	cout << endl << "-----------------CREATION MATERIA :---------------" << endl << endl;
	AMateria*		ice = new Ice();
	AMateria*		cure = new Cure();

	cout << endl << "-----------------LEARNING MATERIA :---------------" << endl << endl;
	src->learnMateria(ice);
	src->learnMateria(cure);
	
	cout << endl << "-----------------DISPLAY MATERIA SOURCE :---------------" << endl << endl;
	cout << *src << endl;

	cout << endl << "-----------------DISPLAY CHARACTER :---------------" << endl << endl;
	cout << character1 << endl;
	cout << character2 << endl;
	cout << character3 << endl;
	
	cout << endl << "-----------------EQUIPE TEST :---------------" << endl << endl;
	AMateria*	tmp;

	tmp = src->createMateria("ice");
	character1.equip(tmp);
	tmp = src->createMateria("ice");
	character1.equip(tmp);

	cout << endl << "-----------------COPY CONSTRUCTOR TEST :---------------" << endl << endl;
	Character	character4 = Character(character1);

	cout << endl << "-----------------EQUIP TEST :---------------" << endl << endl;
	tmp = src->createMateria("cure");
	character1.equip(tmp);
	tmp = src->createMateria("Cce");
	character1.equip(tmp);

	cout << endl << "-----------------ASSIGNATION TEST :---------------" << endl << endl;
	character3 = character1;

	cout << endl << "-----------------EQUIP TEST :---------------" << endl << endl;
	tmp = src->createMateria("cure");
	character1.equip(tmp);
	tmp = src->createMateria("ice");
	character3.equip(tmp);
	
	cout << endl << "-----------------DISPLAY CHARACTER :---------------" << endl << endl;
	cout << character1 << endl;
	cout << character2 << endl;
	cout << character3 << endl;
	cout << character4 << endl;

	cout << endl << "-----------------USE TEST :---------------" << endl << endl;

	cout << endl << "-----------------character 1 USE TEST :---------------" << endl << endl;
	character1.use(0, character2);
	character1.use(1, character2);
	character1.use(2, character2);
	character1.use(3, character2);
	character1.use(4, character2);
	character1.use(-1, character2);

	cout << endl << "-----------------character 2 USE TEST :---------------" << endl << endl;
	character2.use(0, character2);
	character2.use(1, character2);
	character2.use(2, character2);
	character2.use(3, character2);
	character2.use(4, character2);
	character2.use(-1, character2);

	cout << endl << "-----------------character 3 USE TEST :---------------" << endl << endl;
	character3.use(0, character2);
	character3.use(1, character2);
	character3.use(2, character2);
	character3.use(3, character2);
	character3.use(4, character2);
	character3.use(-1, character2);

	cout << endl << "-----------------character 4 USE TEST :---------------" << endl << endl;
	character4.use(0, character2);
	character4.use(1, character2);
	character4.use(2, character2);
	character4.use(3, character2);
	character4.use(4, character2);
	character4.use(-1, character2);

	cout << endl << "-----------------DISPLAY CHARACTER :---------------" << endl << endl;
	cout << character1 << endl;
	cout << character2 << endl;
	cout << character3 << endl;
	cout << character4 << endl;

	cout << endl << "-----------------character 1 UNEQUIP TEST :---------------" << endl << endl;
	character1.unequip(0);
	character1.unequip(1);
	character1.unequip(2);
	character1.unequip(3);
	character1.unequip(4);
	character1.unequip(-1);

	cout << endl << "-----------------character 2 UNEQUIP TEST :---------------" << endl << endl;
	character2.unequip(0);
	character2.unequip(1);
	character2.unequip(2);
	character2.unequip(3);
	character2.unequip(4);
	character2.unequip(-1);

	cout << endl << "-----------------character 3 UNEQUIP TEST :---------------" << endl << endl;
	character3.unequip(0);
	character3.unequip(1);
	character3.unequip(2);
	character3.unequip(3);
	character3.unequip(4);
	character3.unequip(-1);

	cout << endl << "-----------------character 4 UNEQUIP TEST :---------------" << endl << endl;
	character4.unequip(0);
	character4.unequip(1);
	character4.unequip(2);
	character4.unequip(3);
	character4.unequip(4);
	character4.unequip(-1);

	cout << endl << "-----------------character 1 ADDITIONAL UNEQUIP TEST :---------------" << endl << endl;
	tmp = src->createMateria("ice");
	character1.equip(tmp);
	tmp = src->createMateria("ice");
	character1.equip(tmp);
	character1.unequip(1);
	character1.unequip(2);
	character1.unequip(3);
	character1.unequip(4);
	character1.unequip(-1);

	cout << endl << "-----------------CLEANUP MAIN (MATERIA SOURCE AND BASE MATERIA) :---------------" << endl << endl;
	delete src;
	delete ice;
	delete cure; */

	//cout << "-----------------DESTRUCTION CALL---------------" << endl;
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
	return (0);
}