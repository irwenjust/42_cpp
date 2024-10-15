/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:28:38 by likong            #+#    #+#             */
/*   Updated: 2024/10/14 09:48:41 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

static void	forSubject(){
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter*	me = new Character("me");
	
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter*	bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

static void	useAll(ICharacter* player, ICharacter* target){
	for (int i = 0; i < 4; i++)
		player->use(i, *target);
}

static void	forNormal(){
	IMateriaSource*	src = new MateriaSource();
	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(nullptr);

	ICharacter	*me = new Character("me");
	AMateria	*tmp;
	me->equip(nullptr);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("barrett-M82");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "-----------Use all things-----------\n";
	ICharacter	*bob = new Character("bob");
	useAll(me, bob);
	me->use(4, *bob);
	me->use(-1, *bob);
	
	delete tmp;
	delete src;
	delete bob;
	delete me;
}

static void	forNoCure(){
	IMateriaSource*	src = new MateriaSource();
	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(ice);
	src->learnMateria(ice);
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(nullptr);

	ICharacter	*me = new Character("me");
	AMateria	*tmp;
	me->equip(nullptr);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("barrett-M82");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "-----------Use all things-----------\n";
	ICharacter	*bob = new Character("bob");
	useAll(me, bob);
	me->use(4, *bob);
	me->use(-1, *bob);
	
	delete tmp;
	delete src;
	delete bob;
	delete me;
}

static void	forNoIce(){
	IMateriaSource*	src = new MateriaSource();
	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();

	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(ice);
	src->learnMateria(nullptr);

	ICharacter	*me = new Character("me");
	AMateria	*tmp;
	me->equip(nullptr);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("barrett-M82");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << "-----------Use all things-----------\n";
	ICharacter	*bob = new Character("bob");
	useAll(me, bob);
	me->use(4, *bob);
	me->use(-1, *bob);
	
	delete tmp;
	delete src;
	delete bob;
	delete me;
}

static void	forExchange(){
	IMateriaSource*	src = new MateriaSource();
	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(nullptr);

	ICharacter	*me = new Character("me");
	AMateria	*tmp;
	me->equip(nullptr);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("barrett-M82");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter	*bob = new Character("bob");

	AMateria	*floor[10];
	for (int i = 0; i < 10; i++)
    	floor[i] = nullptr;
	Character*	meCopy = dynamic_cast<Character*>(me);
	if (meCopy == nullptr)
		return ;
	floor[0] = meCopy->getInventory(1);
	me->unequip(1);
	me->unequip(1); // should output nothing
	me->use(1, *bob); // should output nothing

	floor[1] = meCopy->getInventory(2);
	me->unequip(2);
	me->unequip(2); // should output nothing
	me->use(2, *bob); // should output nothing

	me->equip(floor[1]);
	floor[1] = nullptr;

	me->equip(floor[0]);
	floor[0] = nullptr;

	useAll(me, bob);

	delete tmp;
	delete src;
	delete bob;
	delete me;
}

static void	forCopy(){
	IMateriaSource*	src = new MateriaSource();
	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(nullptr);

	ICharacter	*me = new Character("me");
	AMateria	*tmp;
	me->equip(nullptr);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("barrett-M82");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter	*bob = new Character("bob");

	Character*	meCopy = dynamic_cast<Character*>(me);
	if (meCopy == nullptr)
		return ;

	std::cout << "\n------Test copy constructor------\n";
	Character	bar0(*meCopy);
	ICharacter	*bar = &bar0;
	useAll(bar, bob);

	std::cout << "\n-------Test copy operator--------\n";
	std::cout << "--before copy assignment operator--\n";
	ICharacter	*hero = new Character("hero");
	useAll(hero, bob);
	std::cout << "--after copy assignment operator---\n";
	*dynamic_cast<Character*>(hero) = *meCopy;
	useAll(hero, bob);

	delete tmp;
	delete src;
	delete hero;
	delete bob;
	delete me;
}

int	main()
{
	std::cout << "\n-----------From subject-------------\n\n";
	forSubject();

	std::cout << "\n-----------From own test------------\n";
	forNormal();

	std::cout << "\n---Exchange materia with 1 and 2 then use all---\n";
	forExchange();

	std::cout << "\n--------If element not exist--------\n";
	std::cout << "\n----------If cure not exist---------\n";
	forNoCure();
	std::cout << "\n----------If ice not exist----------\n";
	forNoIce();

	forCopy();
	
	return (0);
}
