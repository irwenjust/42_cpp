/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:23:41 by likong            #+#    #+#             */
/*   Updated: 2024/10/07 20:59:54 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice: public AMateria{
	public:
		Ice();
		Ice(const Ice &);
		~Ice();

		Ice		&operator = (const Ice &);

		AMateria	*clone() const override;
		void		use(ICharacter &target) override;
};
