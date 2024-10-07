/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 08:29:44 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 20:54:34 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	forClaptrap(){
	ClapTrap	defaultHero;
	ClapTrap	copyHero(defaultHero);

	ClapTrap	hero1("hero1");
	ClapTrap	hero2("hero2");

	hero1.attack("hero2");
	hero2.takeDamage(9);
	hero2.beRepaired(10);
	
	hero1.attack("hero2");
	hero2.takeDamage(11);
	hero2.beRepaired(10);
	
	hero2.attack("hero1");
	
	hero1.attack("hero2");
	hero2.takeDamage(1);
}

void	forScavtrap(){
	ScavTrap	defaultHeroS;
	ScavTrap	copyHeroS(defaultHeroS);

	ScavTrap	hero1S("hero1S");
	ScavTrap	hero2S("hero2S");

	hero1S.attack("hero2S");
	hero2S.takeDamage(20);
	hero2S.beRepaired(10);
	
	hero1S.attack("hero2S");
	hero2S.takeDamage(20);
	hero2S.beRepaired(10);
	
	hero2S.attack("hero1S");
	hero1S.takeDamage(20);
	hero1S.attack("hero2S");
	hero2S.takeDamage(20);
	hero1S.beRepaired(0);
	hero2S.beRepaired(0);

	defaultHeroS.guardGate();
	copyHeroS.guardGate();
	hero1S.guardGate();
	hero2S.guardGate();
}

int	main(void){
	std::cout << "\n----------For Claptrap----------\n\n";
	forClaptrap();

	std::cout << "\n----------For Scavtrap----------\n\n";
	forScavtrap();

	std::cout << "\n----------For Fragtrap----------\n\n";
	FragTrap	defaultHeroF;
	FragTrap	copyHeroF(defaultHeroF);

	FragTrap	hero1F("hero1F");
	FragTrap	hero2F("hero2F");

	hero1F.attack("hero2F");
	hero2F.takeDamage(30);
	hero2F.beRepaired(10);
	
	hero1F.attack("hero2F");
	hero2F.takeDamage(30);
	hero2F.beRepaired(10);
	
	hero2F.attack("hero1F");
	hero1F.takeDamage(30);
	hero1F.attack("hero2F");
	hero2F.takeDamage(30);
	hero1F.beRepaired(0);
	hero2F.beRepaired(0);

	defaultHeroF.highFivesGuys();
	copyHeroF.highFivesGuys();
	hero1F.highFivesGuys();
	hero2F.highFivesGuys();

	return 0;
}
