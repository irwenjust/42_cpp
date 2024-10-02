/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:40:19 by likong            #+#    #+#             */
/*   Updated: 2024/09/26 18:47:45 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	testDestructor(){
	Zombie	zombieA("Foo");
	zombieA.announce();
}

int	main(void){
	testDestructor();
	
	Zombie *zombieB = newZombie("Coo");
	zombieB->announce();
	delete(zombieB);

	randomChump("Boo");
	return (0);
}
