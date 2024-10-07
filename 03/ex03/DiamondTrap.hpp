/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:49:05 by likong            #+#    #+#             */
/*   Updated: 2024/10/03 09:24:36 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{
	private:
		std::string	_name;

	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

		DiamondTrap	&operator = (const DiamondTrap &other);
		void		attack(const std::string& target);
		void		whoAmI();
};
