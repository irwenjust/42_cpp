/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:25:17 by likong            #+#    #+#             */
/*   Updated: 2024/10/08 18:53:47 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character: public ICharacter{
	private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character();
		Character(const std::string &name);
		Character(const Character &other);
		~Character() override;
		
		Character			&operator = (const Character &other);
		
		std::string	const	&getName() const override;
		void				equip(AMateria* m) override;
		void				unequip(int idx) override;
		void				use(int idx, ICharacter &target) override;
		AMateria			*getInventory(int idx);
};
