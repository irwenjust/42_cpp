/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:55:32 by likong            #+#    #+#             */
/*   Updated: 2024/09/27 08:50:30 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), weapon(nullptr){}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}

void	HumanB::attack(void) const{
	if (!this->weapon){
		std::cout << this->_name << " has nothing" << std::endl;
		return ;
	}
	std::cout << this->_name << " attack with" << this->weapon->getType() << std::endl;
}
