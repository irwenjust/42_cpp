/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 08:29:44 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 10:41:48 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void){
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
	
	hero2.attack("hero3");
	
	hero1.attack("hero2");
	hero2.takeDamage(1);

	return 0;
}
