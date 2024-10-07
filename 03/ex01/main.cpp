/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 08:29:44 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 14:12:57 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

int	main(void){
	std::cout << "\n----------For Claptrap----------\n\n";
	forClaptrap();

	std::cout << "\n----------For Scavtrap----------\n\n";
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

	return 0;
}
