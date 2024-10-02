/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:55:34 by likong            #+#    #+#             */
/*   Updated: 2024/09/27 08:50:17 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Weapon.hpp"

class HumanA{
	private:
		std::string	_name;
		Weapon		&weapon;
	
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack(void) const;
};
