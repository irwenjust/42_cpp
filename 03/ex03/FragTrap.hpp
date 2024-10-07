/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:31:24 by likong            #+#    #+#             */
/*   Updated: 2024/10/03 09:22:53 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap{
	public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &other);
		~FragTrap();

		FragTrap	&operator = (const FragTrap &other);
		void		attack(const std::string& target) override;
		void		highFivesGuys();
};
