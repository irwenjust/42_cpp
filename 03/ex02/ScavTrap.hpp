/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:21:30 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 11:45:22 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();

		ScavTrap	&operator = (const ScavTrap &other);
		void		attack(const std::string& target) override;
		void		guardGate();
};
