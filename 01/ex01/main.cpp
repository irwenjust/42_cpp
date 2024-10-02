/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:59:40 by likong            #+#    #+#             */
/*   Updated: 2024/09/26 19:25:45 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void){
	int	amount = 10;
	Zombie	*zombie = zombieHorde(amount, "Foo");
	
	while (--amount >= 0)
		zombie[amount].announce();
	delete [] zombie;

	return (0);
}
