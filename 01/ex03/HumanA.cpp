/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:55:36 by likong            #+#    #+#             */
/*   Updated: 2024/09/27 08:50:15 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
		: _name(name), weapon(weapon){}

void	HumanA::attack(void) const{
	std::cout << this->_name << " attack with " << this->weapon.getType() << std::endl;
}
