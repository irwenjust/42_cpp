/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:55:30 by likong            #+#    #+#             */
/*   Updated: 2024/09/27 08:50:20 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Weapon.hpp"

class HumanB{
	private:
		std::string	_name;
		Weapon		*weapon;

	public:
		HumanB(std::string name);
		void		setWeapon(Weapon &weapon);
		void	attack(void) const;
};
